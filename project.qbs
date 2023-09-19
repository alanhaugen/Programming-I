import qbs

CppApplication {
    consoleApplication: true
    files: [
        "inputfunctions.cpp",
        "main.cpp",
        "polynomial.cpp",
        "polynomial.h",
        "principia.cpp",
        "principia.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
