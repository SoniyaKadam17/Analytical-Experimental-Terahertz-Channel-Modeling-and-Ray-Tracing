c = 3e8; % Speed of light in m/s
load('/Users/soniyanitinkadam/Desktop/NEU/Semester 2 (Spring 2024)/Terahertz Communication for 6G/Assignments/HW2/Data/MATLAB/molecular_absorption.mat'); % path to file
f_THz = f * 1e-12; % Convert frequency to THz
idx = (f_THz >= 0.1) & (f_THz <= 10); % 0.1 THz and 10 THz
f_relevant = f(idx);
distances = [1, 10, 100]; % Distances in meters
% spreading loss array
SpreadingLoss_dB = zeros(length(f_relevant), length(distances));
% Calculate spreading loss
for i = 1:length(distances)
SpreadingLoss_dB(:,i) = 20*log10(4*pi*f_relevant*distances(i)/c);
end
figure; % create figure
hold on; %
colors = ['r', 'g', 'b']; % Color for each line for i = 1:length(distances)
plot(f_THz(idx), SpreadingLoss_dB(:,i), colors(i), 'DisplayName', [num2str(distances(i)) ' meter']); % plot for each distance
end
hold off;
% Label
xlabel('Frequency (THz)'); ylabel('Spreading Loss (dB)'); legend show;
xlim([0.1 10]); % x-axis
ylim([0 200]); % y-axis title('Spreading Loss vs. Frequency');
