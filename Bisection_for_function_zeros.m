% Bisection for finding function zeros

function [c, i] = bisection_for_function_zeros(f, a, b, eps)
    % Algorithm for finding zeros on a given interval of a function
    % USAGE: [xb, ib] = bisekcija(f, zacetek_intervala, konec_intervala, eps);
    format long
    i = 0;
    if(f(a)*f(b) < 0)
        while(abs(b-a) >= eps)
            c = a + (b - a)/2;
            if(f(a)*f(c) < 0)
                b = c;
            else
                a = c;
            end
            i = i + 1;
        end
    elseif(f(a) > 0)
        fprintf('Function is on interval [%f, %f] positive.\n', a, b);
    else
        fprintf('Function is on interval [%f, %f] negative.\n', a, b);
    end
end