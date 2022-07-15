#!/usr/bin/env bash
sed -e '1s/^/[\n/' -e '$s/,$/\n]/' .cfrags/*.json > ./compile_commands.json
