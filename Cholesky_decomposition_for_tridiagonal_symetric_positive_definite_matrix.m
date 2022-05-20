% Cholesky decomposition for tridiagonal symetric positive definite matrix
% Used for solving systems of linear equations

function [V, s] = tridiag_cholesky(A)
    % Cholesky decomposition for tridiagonal symetric positive definite matrix
    % USAGE: [V, s1] = tridiag_cholesky(A);
    n = size(A, 1);
    V = zeros(n);
    V(1,1) = sqrt(A(1,1));
    s = 1;
    for i = 2:n
        V(i, i-1) = A(i, i-1)/V(i-1, i-1);
        V(i, i) = sqrt(A(i, i) - V(i, i-1)^2);
        s = s + 5;
    end
end
    
function [y, s] = direct_insertion_chol(L, b)
    % Algorithm for direct insertion for Cholesky decomposition
    % USAGE: [y, s2] = direct_insertion_chol(V, b);
    n = size(L, 1);
    y = ones(n, 1);
    s = 1;
    y(1) = b(1)/L(1,1);
    for i = 2:n
        y(i) = ( b(i) - L(i, i-1)*y(i-1) )/L(i, i);
        s = s + 3;
    end
end

function [x, s] = reverse_insertion_chol(U, y)
    % Algorithm for reverse insertion for Cholesky decomposition
    % USAGE: [x, s3] = reverse_insertion_chol(V', y);
    n = size(U, 1);
    x = zeros(n, 1);
    x(n) = y(n)/U(n, n);
    s = 1;
    for i = n-1:-1:1
        x(i) = (y(i)-U(i, i+1) * x(i+1))/U(i, i);
        s = s + 3;
    end
end