#include "compiler.ih"

CompileResult Compiler::compile(string const &sourceFile,
    string const &objectFile)
{
    CompileResult st;
    string errFile = "errfile_" + to_string(d_compileNo++) + ".err";

    // command: <compiler> <flags...> -c <src> -o <obj> 2> <errfile>
    string cmd;

    cmd += "g++-15";                 
   
    // for (auto &opt : d_options)     // add commands here
    //     cmd += ' ' + opt + ' ';

    cmd += " -c " + sourceFile;
    cmd += " -o " + objectFile;
    cmd += " 2> " + errFile;

    int sysReturn = system(cmd.c_str());
    st.exitCode = exitCodeFromSystem(sysReturn);
    st.success = (st.exitCode == 0);

    st.stdErrText = readFile(errFile);

    error_code ec;
    filesystem::remove(errFile, ec);    // clean error file

    return st;
}
