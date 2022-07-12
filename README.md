![expl logo](https://github.com/nithinmanoj10/eXpL/blob/master/EXPL%20Banner.png?raw=true)

eXpL is an EXperimental Programming Language based on the compiler made in the [NITC Compiler Lab Course](https://silcnitc.github.io/index.html)

# Installation

Download the latest version of eXpL (v1.0.0) from the GitHub releases page. You'll be provided with a xsm_expl.zip file, which you should extract and save it in your directory of choice.

# Hello World!

To check if the installation process was correct, run the following commands

```
cd xsm_expl/eXpL
```

Inside the `eXpL` directory you will find the `Input_Files` directory. This is where all your programs live.

`hello_world.expl` comes with the compiler when you first install it. Open and view it using your editor of choice

```
int main() {
    begin
        write("Hello World");
        return 1;
    end;
}
```

With still within the `eXpL` directory, execute the following command to run `hello_world.expl`

```
./silc hello_world
```

You should expect this output if you ran all the commands in order given above

```
⏳ Compiling hello_world.expl

✅ Successfully Compiled: Target code saved in target.xsm
🚀 Running target.xsm
Hello World
Machine is halting.
```

# What's next?

With that you can start writing your own programs in eXpL. Check out the GitHub Wiki page to learn more about the language specification.
