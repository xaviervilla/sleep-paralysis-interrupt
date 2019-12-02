MAX=total_acc_x_test(1,1);
for i=1:2947
    for j=1:128
        if MAX<= total_acc_x_test(i,j);
            MAX=total_acc_x_test(i,j);
        end
    end
end
for i=1:2947
    for j=1:128
        if MAX<= total_acc_y_test(i,j);
            MAX=total_acc_y_test(i,j);
        end
    end
end
for i=1:2947
    for j=1:128
        if MAX<= total_acc_z_test(i,j);
            MAX=total_acc_z_test(i,j);
        end
    end
end
MAX    