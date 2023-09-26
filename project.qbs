import qbs

CppApplication {
    consoleApplication: true
    files: [
        "main.cpp",
        "polynomial.cpp",
        "polynomial.h",
        "principia.cpp",
        "principia.h",
        "source/inputfunctions.cpp",
        "source/inputfunctions.h",
        "source/main.cpp",
        "source/main.h",
        "source/polynomial.cpp",
        "source/polynomial.h",
        "source/principia.cpp",
        "source/principia.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
