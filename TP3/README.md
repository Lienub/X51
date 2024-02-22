# X51 - Traitement d'images 

## TP3 : filtre médian, modélisation du bruit

### Filtre médian

Le filtre médian est un filtre non-linéaire très populaire.

On considère une image en niveaux de gris $`f`$ et une fenêtre $`M`$ de taille $`(n\times n)`$, où $`n`$ est un entier impair. Le résultat du filtre médian  de $`f`$ par $`M`$ est obtenu par la procédure suivante :

Pour tous les points p de l'image $`f`$ : 
- on considère la liste des valeurs des points contenus dans la fenêtre M centrée en p ;
- on trie cette liste et on en détermine la valeur *médiane* (valeur en position centrale de la liste triée) ;
- on écrit cette valeur médiane au point p de l'image résultante.
       
#### Travail à réaliser

* Dans le fichier `filtres.cpp` implémenter la fonction :

  ```c++
  Image <uint8_t> filtre_median(const Image <uint8_t> &image, int taille_fenetre)
  ```

  Quelques conseils :

  - Vous pourrez vous appuyer sur la classe `std::vector` pour stocker la liste des valeurs voisines.
  - La méthode `std::vector::push_back` permet d'insérer un élément en queue de liste.
  - On considère que les points voisins situés en dehors de l'image n'ont pas d'influence sur le résultat. On ajoutera dans la liste uniquement les voisins situés à *l'intérieur* du support de l'image. La taille de la liste variera donc en fonction de la position du point considéré.
  - Afin de trier la liste, on pourra utiliser la méthode `std::sort`. 
    Voir : [http://www.cplusplus.com/reference/algorithm/sort/](http://www.cplusplus.com/reference/algorithm/sort/)

* Tester votre fonction dans un main, et analyser les résultats pour des tailles croissantes de fenêtres. Visuellement, quelles différences peut-on observer en comparaison avec un filtre de lissage ?

### Modélisation du bruit

#### Bruit impulsionnel

Dans le fichier `bruit.cpp` écrire la fonction 
```c++
Image <uint8_t> bruit_impulsionnel(const Image<uint8_t> &img, double p)
```
permettant d'ajouter du bruit impulsionnel (ou *poivre et sel*) à une image. Le paramètre `p` correspond à la probabilité qu'un pixel de l'image soit corrompu, avec $`0\leq p \leq 1`$.
Chaque pixel corrompu peut être blanc (valeur 255) ou noir (valeur 0) avec une probabilité 0.5 (une chance sur deux).
Vous pourrez vous appuyer sur la fonction `rand()`  ou utiliser la classe `std::uniform_int_distribution`.
Voir : [http://www.cplusplus.com/reference/random/uniform_int_distribution/](http://www.cplusplus.com/reference/random/uniform_int_distribution/)

#### Bruit gaussien

Dans le fichier `bruit.cpp` écrire la fonction 

```c++
Image <uint8_t> bruit_gaussien(const Image<uint8_t> &img, double sigma)
```

qui ajoute à l'image `img` un bruit gaussien de  moyenne $`\mu=0`$ et d'écart-type $`\sigma=`$`sigma`.
Dans ce modèle de bruit, tous les pixels de l'image sont corrompus : la nouvelle valeur d'un pixel est calculée en ajoutant à la valeur d'origine une valeur aléatoire suivant la loi de probabilité gaussienne $`\mathcal{N}(\mu,\sigma^2)`$. On effectue une troncature sur l'image bruitée : si un pixel a une valeur négative, on la ramène à 0 ; si un pixel a une valeur qui dépasse 255, on la ramène à 255.
Vous pourrez utiliser la classe *std::normal\_distribution* du C++ 11.
Voir : [http://www.cplusplus.com/reference/random/normal_distribution/](http://www.cplusplus.com/reference/random/normal_distribution/)



### Mean Square Error

On introduit une mesure notée MSE, de la dissimilarité entre deux images I et I' de mêmes dimensions $`N\times M`$, définie par :  

```math
MSE(f,f')=\frac{\sum_{x=0}^{N-1} \sum_{y=0}^{M-1} (f(x,y)-f'(x,y))^2}{NM}
```

Cette grandeur permet en particulier de mesurer l'écart entre une image $`f`$ et une version bruitée $`f'`$ de I, ce qui justifie la terminologie d'erreur quadratique moyenne, ou *mean square error*, et l'acronyme MSE.


- Écrire une fonction *computeMSE* qui  retourne la valeur de MSE entre deux images.
 
 
### Tests

Générer les images suivantes à partir de l'image *grumpy.pgm* : 

- Bruit impulsionnel de 15% ;
- Bruit impulsionnel de 40% ;
- Bruit gaussien de moyenne $`\mu=0`$ et d'écart-type $`\sigma=15`$ ;
- Bruit gaussien de moyenne $`\mu=0`$ et d'écart-type $`\sigma=30`$.

Calculer ensuite le MSE entre l'image bruitée et l'image de référence puis entre l'image débruitée et l'image de référence en utilisant les filtres suivants :

- Filtre médian de taille 3 ;
- Filtre médian de taille 7 ;
- Filtre moyenneur de taille 2N+1=3 ; 2N+1=7 ;
- Filtre gaussien avec $`\sigma=1`$ ; $`\sigma=2`$.

Faire un tableau résumant les résultats obtenus ; le meilleur résultat pour chaque type d'image sera mis en valeur (par exemple fonte grasse ou colorée).