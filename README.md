### List of supported features: 
- Arithmetical expressions
- Variables 
- Conditionals
- Loops
- Functions 

### Building 
To build the project you should have `flex`, `bison` ,and `make` installed on a `linux` machine.
Run make to build the project. 
```
make
```

### Parseur 
Pour tester le parseur tout seul. 
Après avoir fait un build. 
`./parseur parser_tests/functions.js`

### Compilateur
Pour tester le compilatuer.
Après avoir fait un build. 
`./compiler compiler_test/variable1-0.js`
Le résultat doit être dans le fichier `out.js.asm` 


