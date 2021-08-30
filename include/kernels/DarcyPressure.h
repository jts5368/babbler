#pragma once

#include "ADKernelGrad.h"

/**
 * Computes the residual contribution: K / mu * grad_test * grad_u.
 */
class DarcyPressure : public ADKernelGrad
{
public:
  static InputParameters validParams();

  DarcyPressure(const InputParameters & parameters);

protected:
  /// ADKernel objects must override precomputeQPResidual
  virtual ADRealVectorValue precomputeQpResidual() override;

  /// The variables which hold the value for K and mu
  const Real & _permeability;
  const Real & _viscosity;
};
