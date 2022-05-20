% LU decomposition of a matrix with direct and reverse insertion
% Used for solving systems of linear equations

function [L, U] = LU_decomposition(A)
    % Algorithm for LU decomposition of a matrix
    % USAGE: [L, U] = LU_decomposition(A);
    n = size(A, 1);
    L = eye(n);
    for i = 1:n-1
        for j = i+1:n
            L(j, i) = A(j, i)/A(i, i);
                for k = i + 1:n
                    A(j, k) = A(j, k) - L(j, i)*A(i, k);
                end
        end
    end
    U = triu(A);
end

function y = direct_insertion(L, b)
    % Algorithm for direct insertion
    % USAGE: y = direct_insertion(L, b);
    n = size(L, 1);
    y = ones(n, 1); 
    for i = 1:n
        y(i) = b(i) - L(i, 1:i-1)*y(1:i-1);
    end
end

function x = reverse_insertion(U, y)
    % Algorithm for reverse insertion
    % USAGE: x = reverse_insertion(U, y);
    n = size(U, 1);
    x = ones(n, 1);        
    x(n) = y(n)/U(n, n);        
    for i = n-1:-1:1
        x(i) = (y(i)-U(i, i+1:n) * x(i+1:n))/U(i, i);
    end
end