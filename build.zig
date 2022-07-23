const std = @import("std");


pub fn build(b: *std.build.Builder) !void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();
   const flags = &.{
            "-DPACKAGE_VERSION=\"0.0.1\"",
       "-gen-cdb-fragment-path", ".cfrags", "-g", "--std=c99"
    };
    const smf = b.addStaticLibrary("smf", null);
    {
        smf.setTarget(target);
        smf.setBuildMode(mode);
        smf.linkLibC();
        smf.install();
        smf.addIncludeDir("src");
        smf.addCSourceFiles(&.{
            "src/smf.c",
            "src/smf_decode.c",
            "src/smf_load.c",
            "src/smf_save.c",
            "src/smf_tempo.c",
            "src/geelib.c"
            }, flags);
    }

    const smfsh = b.addExecutable("smfsh", null);
    {
        smfsh.setTarget(target);
        smfsh.setBuildMode(mode);
        smfsh.install();
        // smfsh.linkSystemLibrary("glib-2.0");
        smfsh.linkLibC();
        smfsh.addIncludeDir("src");
        smfsh.linkLibrary(smf);
        smfsh.addCSourceFiles(&.{
            "src/smfsh.c"
            }, flags);
    }

    const main = b.addExecutable("in-c", null);
    {
        main.setTarget(target);
        main.setBuildMode(mode);
        main.install();
        main.linkLibC();
        main.addIncludeDir("src");
        main.linkLibrary(smf);
        main.addCSourceFiles(&.{
            "src/in-c.c"
            }, flags);
    }

    // const rmcdb = b.addSystemCommand(&.{
    //     "./clearcfrags.sh"
    // });
    const cdbgen = b.addSystemCommand(&.{
        "./gencdb.sh"
    });
    // smf.step.dependOn(&rmcdb.step);

    smfsh.step.dependOn(&smf.step);
    main.step.dependOn(&smf.step);

    cdbgen.step.dependOn(&smfsh.step);
    cdbgen.step.dependOn(&main.step);

    b.getInstallStep().dependOn(&cdbgen.step);
}
