import qbs

CppApplication {
    consoleApplication: true
    files: [
        "source/file.cpp",
        "source/file.h",
        "source/folder.cpp",
        "source/folder.h",
        "source/main.cpp",
        "source/main.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
