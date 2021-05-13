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

## Generation AST 


La structure de données utilisé pour la generation d'AST est un arbre dont chaque noeud pointe sur son fils (chils) et ses freres(next) 
le choix de cet arbre est en relation avec les instruction qui peuvent avoir plusieurs branches , on a essayer de le genaraliser a fin qu'il soit generé par n'importe quelle instruction 
exempe :
la boulce for :
sa grammaire : for(expression;expression;expression){ program}
l'arbre généré est un abre quinaire.
l'instruction conditionnel if:
if(expression){program}
l'abre généré est binaire 


