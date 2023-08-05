
TODO
- add the parsing part of these (half of it done)
- error for parsing: all possible combinations of brackets and of & and of ors,

- attack the execution : one symbol at a time and test once after the other- be inspired by the outline of Anthony
- AND OR
- brackets (subshell)

IF ALL THIS is bad ==> allow one day for wildcard

```bash
a=3 ls
echo $a
```

## pipeline

```bash
a | b | c
```
# each command runs in parallel
# the output of each command is used as the input of the next command
fork a
fork b
fork c
while(waitpid(-1, somthing, 0))

## Example of mix pipe, AND and OR

Thinking about a mix of everything

```bash
a | b && c || d
```

fork a
fork b
while(waitpid(-1, somthing, 0))
if (exit code == 0)
{
	fork c
	while(waitpid(-1, somthing, 0))
}
if (exit code != 0)
{
	fork d
	while(waitpid(-1, somthing, 0))
}

## Example a chain of AND

Thinking about a chain of AND

```bash
a | b && c && d
```

fork a
fork b
while(waitpid(-1, somthing, 0))
if (exit code == 0)
{
	fork c
	while(waitpid(-1, somthing, 0))
}
if (exit code == 0)
{
	fork d
	while(waitpid(-1, somthing, 0))
}

## Example a chain of OR

Thinking about a chain of OR

```bash
a | b || c || d
```

fork a
fork b
while(waitpid(-1, somthing, 0))
if (exit code != 0)
{
	fork c
	while(waitpid(-1, somthing, 0))
}
if (exit code != 0)
{
	fork d
	while(waitpid(-1, somthing, 0))
}
