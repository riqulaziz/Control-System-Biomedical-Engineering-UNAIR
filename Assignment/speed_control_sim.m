clear; clc; 

M = 26;
% Variables of DC Motor System %
R  = 0.2+M/2000 ; %Ohm
L  = 0.01-M/40000;%Henry
Ka = 6e-5;        %Motor Torque Coef / Nms
Kb = 5.4e-2;      %back emf coef / V/(rad/s)
J  = 5.4e-5;      %kg.m^2
b  = 4e-4;        %friction coef

% Variables of PID Tuning %
Kp = 20;  %Gain of the proportional control
Ki = 100; %Gain of the integral control
Kd = 0.1; %Gain of the derivative control

% r(t) value
for t = 1:1000
    r(t) = 100;
end
for t = 1000:2000
    r(t) = 50;
end
for t = 2000:3001
    r(t) = 150;
end
% d(t) value
for t = 1:500
    d(t) = 0.1;
end
for t = 500:2500
    d(t) = 0.2;
end
for t = 2500:3001
    d(t) = 0.1;
end

t = [0:0.001:3]';          %time vector
r = r'; d = d';
Tspan = (0.001:0.001:3)';
[T,x,y]=sim('Motor_Model_sim',Tspan,[],[t,r,d]);
figure(2)
subplot(5,1,1),plot(t,r),title('Set-Point'),ylabel('Voltage (V)'),xlabel('Time (s)');
subplot(5,1,2),plot(T,y(:,1)),title('Armature Voltage'),ylabel('Voltage (V)'),xlabel('Time (s)');
subplot(5,1,3),plot(T,y(:,2)),title('Motor Torque'),ylabel('Torque (Nm)'),xlabel('Time (s)');
subplot(5,1,4),plot(t,d),title('Load Torque'),ylabel('Voltage (V)'),xlabel('Time (s)'),ylim([-0.2 0.3]);
subplot(5,1,5),plot(T,y(:,3)),title('Speed'),ylabel('Angular Speed (rad/s)'),xlabel('Time (s)');