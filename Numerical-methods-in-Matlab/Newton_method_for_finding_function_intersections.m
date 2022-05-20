% Tangent/Newton method for finding function intersections

function [xn, i] = tangent_newton_method(F, J, x0, eps)
    % Algorithm of tangent/Newton method for finding function intersections
    % USAGE:
    % F = @(x) [F ; G];     Matrix of functions
    % J = @(x) [diff(F, x(1))  diff(F, x(2)) ; diff(G, x(1))  diff(G, x(2))];       Jacobian of F
    % [xtn, itn] = tangent_newton_method(F, J, aproximation, eps)
    format long
    x0 = x0(:);
    for i=1:100
        xn = x0 - J(x0)\F(x0);
        if (norm(xn-x0) < eps)
            break;
        end
        x0 = xn;
    end
end