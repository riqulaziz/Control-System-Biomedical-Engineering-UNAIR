clc;clear;close all;
Gc=tf(1,[1 1],'InputDelay',1)
K=0.3;
Gk=tf(K,[1 0])
Gf=K+Gk
Gcp=series(K,Gc);
Gcl=feedback(Gcp,1)
figure;step(Gcl)
