% LU decomposition with pivoting
% Used for solving systems of linear equations

function [L, U, P] = LU_decomposition_pivoting(A)
    % Algorithm for LU decomposition with pivoting
    % USAGE: [L, U, P] = LU_decomposition_pivoting(A);
    n = size(A, 1);
    P = eye(n); 
    for i = 1:n-1
        % Find max element in first column
        [~, imax] = max(abs(A(i:n, i)));
        imax = imax + i - 1;        
        % Switching i-max rows with current row
        A([i, imax], :) = A([imax, i], :);
        P([i, imax], :) = P([imax, i], :);
        A(i+1:n, i) = A(i+1:n, i)/A(i, i);
        A(i+1:n, i+1:n) = A(i+1:n, i+1:n) - A(i+1:n, i)*A(i, i+1:n);
    end
    % Seting L and U matrix
    L = eye(n) + tril(A, -1);
    U = triu(A);
end