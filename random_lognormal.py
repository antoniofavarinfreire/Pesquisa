import numpy as np
import numpy.random as npr

DEFAULT_PARAMS = {
    'fator_subr': 40.0,
    'gamma': (7.0 , 14.0),
    'alpha': (4.1, 7.0),
    'R0_': (2.5, 6.0),
}


def make_lognormal_params_95_ci(lb, ub):
    mean = (ub*lb)**(1/2)
    std = (ub/lb)**(1/4)
    return mean, std

def run_SEIR_BAYES_model(R0_params, runs):
    R0_ = npr.lognormal(*map(np.log, R0_params),runs)
    print('Map = ', *map(np.log, R0_params))
    print('R0_', R0_)

if __name__ == '__main__':

    R0_params = make_lognormal_params_95_ci(*DEFAULT_PARAMS["R0_"])
    runs = 4
    print("R0_params = ", R0_params)
    R = run_SEIR_BAYES_model(R0_params, runs)
