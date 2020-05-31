/*
 * Ici j'aurais bien fait un mutex pour la gestion des pistes mais voilà l'explication. En théorie, on devrait avoit une chose du genre

typedef struct s_mutex_pistes {
    pthread_mutex_t mutex;
    pthread_cond_t conditionsPistes[2];
    pthread_cont_t avionQuelconque;
}

 *     Mais ceci est totalement inutile, jusqu'au dernier bout de code.
 *
 *     le mutex réserve l'accès aux conditions et des ressources partagées, mais quelles sont ces conditions et ressources
 * partagées ? Les conditions seraient les conditions des pistes et la condition d'un piste quelconque.
 *
 *     la condition avionQuelconque est inutile car elle revient à la condition avion quelconque. Car quand il y a un
 * atterrissage/décollage avec un avion, on libère forcément une piste quelconque.
 *
 *     la condition conditionsPistes ne nous sert à rien car la piste n'a pas de volonté propre, nous le controleur sommes
 *  le seul à autoriser le décollage / atterissage des avions.
 */
