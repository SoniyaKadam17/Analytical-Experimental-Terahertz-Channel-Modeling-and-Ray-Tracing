% Constants
c = 3e8; % Speed of light in m/s
load('/Users/soniyanitinkadam/Desktop/NEU/Semester 2 (Spring 2024)/Terahertz Communication for 6G/Assignments/HW2/Data/MATLAB/molecular_absorption.mat'); f_THz = f * 1e-12; % Convert frequency to THz
idx = (f_THz >= 0.1) & (f_THz <= 10); % 0.1 THz and 10 THz
f_relevant = f(idx);
k_relevant = k(idx);
% Distances
distances = [1, 10, 100]; % Distances in meters
% Molecular Absorption Loss for each distance
L = zeros(length(f_relevant), length(distances)); % pre-allocate a matrix for absorption loss values
for i = 1:length(distances)
L(:,i) = 10*log10(exp(k_relevant * distances(i)));
end
% spreading loss
SpreadingLoss_dB = zeros(length(f_relevant), length(distances));
% Calculate spreading loss
for i = 1:length(distances)
SpreadingLoss_dB(:,i) = 20*log10(4*pi*f_relevant*distances(i)/c);
end
% Total Path Loss
TotalPathLoss_dB = L + SpreadingLoss_dB; figure; % create figure
hold on; % hold on for multiple plots for i = 1:length(distances)
plot(f_THz(idx), TotalPathLoss_dB(:,i), plot_colors(i), 'DisplayName', [num2str(distances(i)) ' meter']); % plot for each distance
end
hold off; % Label
xlabel('Frequency (THz)');
ylabel('Total Path Loss (dB)');
xlim([0 5]); % x-axis
ylim([0 2000]);% y-axis
title('Path Loss vs. Frequency for Different Distances');
