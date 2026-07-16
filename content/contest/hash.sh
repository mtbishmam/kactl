#!/bin/sh

cpp_cmd=${CPP:-cpp}
if ! "$cpp_cmd" -dD -P -fpreprocessed </dev/null >/dev/null 2>&1 && command -v cpp-15 >/dev/null 2>&1; then
	cpp_cmd=cpp-15
fi

"$cpp_cmd" -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | cut -c-6
