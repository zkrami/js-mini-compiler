### List of supported features(parser): 
- Arithmetical expressions
- Variables 
- Conditionals
- Loops
- Functions 

### List of supported features(compiler): 
- Arithmetical expressions
- Variables 
- Conditionals
- Loops


### Building 
To build the project you should have `flex`, `bison` ,and `make` installed on a `linux` machine.
Run make to build the project. 
```
make
```

(To build the parser alone you should `checkout` to the `parseur` branch and run `make`)

### Parseur 
Pour tester le parseur tout seul. 
Après avoir fait un build. 
`./parseur parser_tests/functions.js`

### Compilateur
Pour tester le compilatuer.
Après avoir fait un build. 
`./compiler compiler_test/variable1-0.js`
Le résultat doit être dans le fichier `out.js.asm` 


### Reste à faire 
- Des types dynamiques 
- Rajouter d'analyse pour traiter la sucre syntaxique (`for loop` , `arrow functions` )
- Functions 
- Hosting
- Objects 
- Exceptions 