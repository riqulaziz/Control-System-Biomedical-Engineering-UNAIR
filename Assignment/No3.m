clc;clear;close all;
Kc=1;
Gp=tf(2,[300 65 1],'InputDelay',1.5)
Gv=tf(0.5,[3 1],'InputDelay',0.3)
Gm=tf(3,[2 1],'InputDelay',0.2)
Gc=Kc;
G1=series(Gp,Gv);
G2=series(Gm,Gc);
G3=series(G1,G2);
%%%%%
Gk=tf(3,[10 1],'InputDelay',5)
G4=series(Kc,Gk)
hold on
step(G3)
step(G4)
% Gc=0.3;
% Gk=tf(K,[1 0])
% Gf=K+Gk
% Gcp=series(K,Gc);
% Gcl=feedback(Gcp,1)
% figure;step(Gcl)
