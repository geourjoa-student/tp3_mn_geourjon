**********************************************
		Compte rendu TP3 MN 
**********************************************

Le sujet n'a pas été traité en intégralité (trop long pour une seule personne), je n'ai pas traité tri_inf et tri_sup avec optimisation de la réprésentation d'une matrice.
Pour l'évaluation des performance, perf ne m'indique pas le taux de branchements manqués. Peut être est ce du à mon processuer (relativement vieux) qui ne calcule pas cette métrique.
Il vous est possible de réévaluer facilement les performances avec le script bash "script_cr.sh" qui générera un fichier résumant les actions de perf sur tout les programmes.

*****************************
Configuration du processeur :
*****************************

Modèle	: Intel(R) Pentium(R) CPU        P6100  @ 2.00GHz
Cache L3 : 3MB
Nombre coeurs : 2
RAM : 4GB
Date de lancement par Intel : Q3'10

Fiche constructeur :
http://ark.intel.com/fr/products/50175/Intel-Pentium-Processor-P6100-3M-Cache-2_00-GHz

***********
Compilation
***********

> make

*****************************
Caractéristiques des matrices
*****************************

La taille de matrice utilisé est 128 * 128 pour que le programme tienne dans le
cache L3  3MB du processeur. Les matrices sont des matrices de nombre flottants


 Performance counter stats for './diag':

          0,478215      task-clock (msec)         #    0,500 CPUs utilized          
                 2      context-switches          #    0,004 M/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
                63      page-faults               #    0,132 M/sec                  
           748 627      cycles                    #    1,565 GHz                    
           483 020      stalled-cycles-frontend   #   64,52% frontend cycles idle   
           224 941      stalled-cycles-backend    #   30,05% backend  cycles idle   
           541 620      instructions              #    0,72  insns per cycle        
                                                  #    0,89  stalled cycles per insn
           122 653      branches                  #  256,481 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,000957013 seconds time elapsed


 Performance counter stats for './diag':

            11 376      cache-references                                            
             3 830      cache-misses              #   33,667 % of all cache refs    

       0,001195284 seconds time elapsed


 Performance counter stats for './tri_inf':

          0,482618      task-clock (msec)         #    0,504 CPUs utilized          
                 2      context-switches          #    0,004 M/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
                61      page-faults               #    0,126 M/sec                  
           819 155      cycles                    #    1,697 GHz                    
           523 917      stalled-cycles-frontend   #   63,96% frontend cycles idle   
           347 154      stalled-cycles-backend    #   42,38% backend  cycles idle   
           614 735      instructions              #    0,75  insns per cycle        
                                                  #    0,85  stalled cycles per insn
           130 763      branches                  #  270,945 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,000956812 seconds time elapsed


 Performance counter stats for './tri_inf':

            12 308      cache-references                                            
             3 755      cache-misses              #   30,509 % of all cache refs    

       0,001000227 seconds time elapsed


 Performance counter stats for './tri_sup':

          0,456735      task-clock (msec)         #    0,478 CPUs utilized          
                 2      context-switches          #    0,004 M/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
                59      page-faults               #    0,129 M/sec                  
           774 283      cycles                    #    1,695 GHz                    
           483 714      stalled-cycles-frontend   #   62,47% frontend cycles idle   
           267 078      stalled-cycles-backend    #   34,49% backend  cycles idle   
           597 042      instructions              #    0,77  insns per cycle        
                                                  #    0,81  stalled cycles per insn
           127 516      branches                  #  279,190 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,000956401 seconds time elapsed


 Performance counter stats for './tri_sup':

            12 083      cache-references                                            
             3 449      cache-misses              #   28,544 % of all cache refs    

       0,000916389 seconds time elapsed


 Performance counter stats for './produit_scalaire_vecto':

          0,525811      task-clock (msec)         #    0,495 CPUs utilized          
                 2      context-switches          #    0,004 M/sec                  
                 1      cpu-migrations            #    0,002 M/sec                  
                47      page-faults               #    0,089 M/sec                  
           698 103      cycles                    #    1,328 GHz                    
           481 030      stalled-cycles-frontend   #   68,91% frontend cycles idle   
           305 891      stalled-cycles-backend    #   43,82% backend  cycles idle   
           418 198      instructions              #    0,60  insns per cycle        
                                                  #    1,15  stalled cycles per insn
            85 439      branches                  #  162,490 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,001061822 seconds time elapsed


 Performance counter stats for './produit_scalaire_vecto':

            10 231      cache-references                                            
             2 461      cache-misses              #   24,054 % of all cache refs    

       0,000869549 seconds time elapsed


 Performance counter stats for './tri_inf_vecto':

          0,479383      task-clock (msec)         #    0,512 CPUs utilized          
                 2      context-switches          #    0,004 M/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
                60      page-faults               #    0,125 M/sec                  
           749 839      cycles                    #    1,564 GHz                    
           478 849      stalled-cycles-frontend   #   63,86% frontend cycles idle   
           265 179      stalled-cycles-backend    #   35,36% backend  cycles idle   
           545 975      instructions              #    0,73  insns per cycle        
                                                  #    0,88  stalled cycles per insn
           120 958      branches                  #  252,320 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,000936714 seconds time elapsed


 Performance counter stats for './tri_inf_vecto':

            11 149      cache-references                                            
             3 403      cache-misses              #   30,523 % of all cache refs    

       0,000848889 seconds time elapsed


 Performance counter stats for './tri_sup_vecto':

          0,442759      task-clock (msec)         #    0,518 CPUs utilized          
                 2      context-switches          #    0,005 M/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
                61      page-faults               #    0,138 M/sec                  
           749 796      cycles                    #    1,693 GHz                    
           477 020      stalled-cycles-frontend   #   63,62% frontend cycles idle   
           298 249      stalled-cycles-backend    #   39,78% backend  cycles idle   
           556 999      instructions              #    0,74  insns per cycle        
                                                  #    0,86  stalled cycles per insn
           122 793      branches                  #  277,336 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,000854739 seconds time elapsed


 Performance counter stats for './tri_sup_vecto':

            13 028      cache-references                                            
             4 113      cache-misses              #   31,570 % of all cache refs    

       0,000941871 seconds time elapsed


 Performance counter stats for './produit_matricielle_vecto':

          0,520560      task-clock (msec)         #    0,545 CPUs utilized          
                 2      context-switches          #    0,004 M/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
                88      page-faults               #    0,169 M/sec                  
           953 715      cycles                    #    1,832 GHz                    
           563 023      stalled-cycles-frontend   #   59,03% frontend cycles idle   
           352 732      stalled-cycles-backend    #   36,99% backend  cycles idle   
           845 100      instructions              #    0,89  insns per cycle        
                                                  #    0,67  stalled cycles per insn
           199 517      branches                  #  383,274 M/sec                  
     <not counted>      branch-misses              (0,00%)

       0,000954592 seconds time elapsed

 Performance counter stats for './produit_matricielle_vecto':

            15 103      cache-references                                            
             5 810      cache-misses              #   38,469 % of all cache refs    

       0,001340285 seconds time elapsed

**********
Conclusion
**********

Même si il était long, ce TP était vraiment très intéressant et m'a permis de vraiment comprendre le cours (qui m'était resté relativement obscure même après relecture). 

