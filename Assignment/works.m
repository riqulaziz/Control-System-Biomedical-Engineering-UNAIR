clc;clear;close all;
M=2;    %NIM
L=0.01-M/40000 ;
R=0.2+M/2000;
Ka=6e-5;
Kb=5.5e-2;
J=5.4e-5;
b=4e-4;
Ks=1;
Ki=100;
Kp=0.1;
Kd=20;
sampTime=1e-3;
waktu=0:sampTime:3;

for t=1:1000
    r(t)=100;
end
for t=1000:2000
    r(t)=50;
end
for t=2000:3001
    r(t)=150;
end

for t=1:500
    d(t)=0.1;
end
for t=500:2500
    d(t)=0.2;
end
for t=2500:3001
    d(t)=0.1;
end

t=0:1e-3:3;
r=r';d=d';t=t';
%%% Figure
simOut=sim('cobaTugas','SimulationMode','normal','TimeOut',3,'SaveTime','on','TimeSaveName','tout', ...
            'SaveState','on','StateSaveName','xoutNew',...
            'SaveOutput','on','OutputSaveName','youtNew')
figure(1)
subplot(5,1,1);plot(simOut.r1)
title('Set Point');ylabel('rad/sec');ylim([30 170])
subplot(5,1,2);plot(simOut.d1)
title('Disturbance');ylabel('Nm');ylim([0 0.3])
subplot(5,1,3);plot(simOut.u)
title('Voltage Armature');ylabel('Volt')
subplot(5,1,4);plot(simOut.T)
title('Torque');ylabel('Nm');ylim([0 0.5])
subplot(5,1,5);plot(simOut.w)
title('Angular Velocity');ylabel('rad/sec')


