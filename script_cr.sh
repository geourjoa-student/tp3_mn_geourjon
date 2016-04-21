#!/bin/bash

perf stat ./diag 2>> cr 
perf stat -e cache-references -e cache-misses ./diag 2>> cr 

perf stat ./tri_inf 2>> cr 
perf stat -e cache-references -e cache-misses ./tri_inf 2>> cr 

perf stat ./tri_sup 2>> cr 
perf stat -e cache-references -e cache-misses ./tri_sup 2>> cr 

perf stat ./produit_scalaire_vecto 2>> cr 
perf stat -e cache-references -e cache-misses ./produit_scalaire_vecto 2>> cr 

perf stat ./tri_inf_vecto 2>> cr 
perf stat -e cache-references -e cache-misses ./tri_inf_vecto 2>> cr 

perf stat ./tri_sup_vecto 2>> cr 
perf stat -e cache-references -e cache-misses ./tri_sup_vecto 2>> cr 

perf stat ./produit_matricielle_vecto 2>> cr 
perf stat -e cache-references -e cache-misses ./produit_matricelle_vecto 2>> cr 
