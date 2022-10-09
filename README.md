## Monty Interpreter
Monty 0.98 is a scripting language that is first compiled into Monty byte codes. The Monty bytes code files are usually of `.m` extension and contain one instruction per line.
The interpreter reads the files and interprets the opcodes therein.

### Usage
Available files are compiled in this format:

```
 gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

To run the interpreter:

```
 ./monty bytecode_file
```

### Opcodes
Available Operation codes:
| Opcode | Description |
|---------------- | -----------|
|push   | Pushes an element to the stack. e.g (`push <int>` # pushes `<int>` unto the stack)|
|pall   | Prints all the values on the stack, starting from the top of the stack.|
|pint   | Prints the value at the top of the stack.|
|pop    | Removes the top element of the stack.|
|swap   | Swaps the top two elements of the stack.|
|add    | Adds the top two elements of the stack. The result is stored in the second node, and the first node is removed.|
|nop    | This does nothing.|
|sub    | Subtracts the top element from the second top element of the stack. The result is then stored in the second node, and the first node is removed.|
|div    | Divides the top element of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mul | Multiplies the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
|mod    | Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|#      | When the first non-space of a line is a `#` the line will be treated as a comment.|
|pchar  | Prints the integer stored at the top of the stack as its ascii value representation.|
|pstr   | Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.|
|rotl   | Rotates the top of the stack to the bottom.|
|rotr   | Rotates the bottom of the stack to the top.|
|stack  | This is the default behavior. Sets the format of the data into a stack (LIFO).|
|queue  | Sets the format of the data into a queue (FIFO).|

* Monty byte code files can contain blank lines and any additional text after the opcode or its required argument is ignored. 
* There can be any number of spaces before or after the opcode and its argument.

#### Example

Push values onto the stack and prints them, then print the top element of the stack.

```
$ cat test.m
push 1
push 2
push 3
pall
pint
$ ./monty test.m
3
2
1
3
```
