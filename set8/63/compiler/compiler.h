#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include <atomic>

struct CompileResult
{
    int exitCode = 0;
    bool success = false;
    std::string stdErrText;
};

class Compiler
{
    // Options d_options;
    std::atomic<size_t> d_compileNo;    // for unique errfiles

    public:
        // Compiler(Options const &options);
        Compiler();

        CompileResult compile(std::string const &sourceFile,
                                std::string const &objectFile);
    private:
        int exitCodeFromSystem(int sysReturn);
        std::string readFile(std::string const &fileName);

};

#endif