clear all;
load('/Users/soniyanitinkadam/Desktop/NEU/Semester 2 (Spring 2024)/Terahertz Communication for 6G/Assignments/HW2/Data/MATLAB/molecular_absorption.mat'); % Load file path
f_THz = f * 1e-12; % Convert frequency to THz for easier handling
idx = (f_THz >= 0.1) & (f_THz <= 10); % 0.1 THz and 10 THz
f_relevant = f(idx);
k_relevant = k(idx);
distances = [1, 10, 100]; % distances in meters
L = zeros(length(f_relevant), length(distances)); % loss value storage
for i = 1:length(distances)
L(:,i) = 10*log10(exp(1)) * k_relevant * distances(i);
end
% range of loss values
disp(['Loss at 1m: Min = ', num2str(min(L(:,1))), ' dB, Max = ', num2str(max(L(:,1))), ' dB']);
disp(['Loss at 10m: Min = ', num2str(min(L(:,2))), ' dB, Max = ', num2str(max(L(:,2))), ' dB']);
disp(['Loss at 100m: Min = ', num2str(min(L(:,3))), ' dB, Max = ', num2str(max(L(:,3))), ' dB']);
figure;
hold on;
plot(f_THz(idx), L(:,1), 'DisplayName','1 meter'); % plot for 1 meter plot(f_THz(idx), L(:,2), 'DisplayName','10 meters'); % plot for 10 meters plot(f_THz(idx), L(:,3), 'DisplayName','100 meters'); % plot for 100 meters hold off;
% Label
xlabel('Frequency (THz)');
ylabel('Molecular Absorption Loss (dB)');
legend show;
xlim([0.1 1.6]); % Set x-axis
ylim([0 100]); % Set y-axis
title('Molecular Absorption Loss vs. Frequency'); %adding the title of the plot
