#!/usr/bin/env python3
import sys
import os

HPP = """#pragma once

#include "action.hpp"

class {classname} : public Action
{{
public:
    {classname}();

    void affect(Fighter &affected) override;
}};
"""

CPP = """#include "{filename}.hpp"
#include "fighter.hpp"

{classname}::{classname}()
{{
    name = "ABILITY NAME";
    description = "ABILITY DESCRIPTION";
}}

void {classname}::affect(Fighter &affected)
{{
}}
"""


def main():
    if len(sys.argv) < 2:
        print("Usage: make_action.py <ClassName>")
        sys.exit(1)

    classname = sys.argv[1]
    filename = classname.lower().replace(" ", "")

    # יצירת התיקייה אם לא קיימת
    out_dir = os.path.join("src", "actions")
    os.makedirs(out_dir, exist_ok=True)

    # נתיבי קבצים
    hpp_path = os.path.join(out_dir, f"{filename}.hpp")
    cpp_path = os.path.join(out_dir, f"{filename}.cpp")

    # בדיקה אם הקבצים כבר קיימים
    for path in (hpp_path, cpp_path):
        if os.path.exists(path):
            print(f"Error: {path} already exists. Aborting.")
            sys.exit(1)

    # כתיבה
    with open(hpp_path, "w", encoding="utf-8") as f:
        f.write(HPP.format(classname=classname, filename=filename))

    with open(cpp_path, "w", encoding="utf-8") as f:
        f.write(CPP.format(classname=classname, filename=filename))

    print(f"Created {hpp_path} and {cpp_path}")


if __name__ == "__main__":
    main()
