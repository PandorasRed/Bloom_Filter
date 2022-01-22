# Bloom_Filter
Implementation d'un Bloom filter en c++ pour https://github.com/yoann-dufresne/bloomtest

# Compilation
la commande :
```bash
    make
```
nettoie le dossier de tous les fichier compiler et recompile le projet en entier

# Utilisation

```bash
  #           fichier     k    n    nf  r
  ./bloomTest ecoli.fasta 31 456637 3 10000
```
lance le programme pour créer un bloom filter de taille n avec nf fonctions de hash,k la taille des kmer, et r le nombre de requetes aléatoire testé dessus,
affiche les kmer tester et si ils sont présents ou non.