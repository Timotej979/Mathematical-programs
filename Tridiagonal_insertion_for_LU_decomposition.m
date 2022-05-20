% Tridiagonal insertion for LU decomposition
% Used for solving systems of linear equations

function y = tridiag_direct_insertion(L, b)
    % Algorithm for direct insertion for tridiagonal matrix
    % USAGE: y = tridiag_direct_insertion(L, b);
    n = size(L,1);
    l = diag(L,-1);
    y = zeros(n,1);
    y(1) = b(1);
    for i = 2:n
        y(i) = b(i) - l(i-1)*y(i-1);
    end
end

function x = tridiag_reverse_insertion(U, y)
    % Algorithm for reverse insertion for tridiagonal matrix
    % USAGE: x = tridiag_reverse_insertion(U, y);
    n = size(U,1);
    u = diag(U);
    d = diag(U,1);
    x = zeros(n,1);
    x(n) = y(n)/u(n);
    for i = n-1:-1:1
        x(i) = (y(i) - d(i)*x(i+1))/u(i);
    end
end