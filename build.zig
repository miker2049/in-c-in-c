const std = @import("std");


pub fn build(b: *std.build.Builder) !void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const smfsh = b.addExecutable("smfsh", null);
    {
        smfsh.setTarget(target);
        smfsh.setBuildMode(mode);
        smfsh.install();
        smfsh.linkSystemLibrary("glib-2.0");
        smfsh.linkLibC();
        smfsh.addIncludeDir("src");
        smfsh.addCSourceFiles(&.{
            "src/smf.c",
            "src/smf_decode.c",
            "src/smf_load.c",
            "src/smf_save.c",
            "src/smf_tempo.c",
            "src/smfsh.c"
            }, &.{
            "-DPACKAGE_VERSION=\"0.0.1\"",
            "-gen-cdb-fragment-path", ".cfrags"
        });
    }

    const cdbgen = b.addSystemCommand(&.{
        "./gencdb.sh"
    });
    cdbgen.step.dependOn(&smfsh.step);

    b.getInstallStep().dependOn(&cdbgen.step);
}
