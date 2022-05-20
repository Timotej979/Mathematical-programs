% Tangent method for solving DE systems

function [x,i] = tangent_DE_system_method(F, J, x0, eps)
    % Algorithm solves a system of equations problem F(x)=0 with tangent/Newton method
    % USAGE: [x,i] = tangent_DE_system_method(F, J, x0, eps);
    % INPUT DATA:
    % F vector of given functions
    % J Jacobian of a given vector of functions
    % x0 vector of function aproximations
    % eps desired accuracy
    % OUTPUT DATA:
    % x vector of system solutions with given accuracy
    % i number of required iterations
    
    x0 = x0(:);
    for i = 1:100
        x = x0-J(x0)\F(x0);
        if norm(x-x0) < eps
            break;
        end
        x0 = x;
    end
end