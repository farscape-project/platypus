#include "MFEMVectorNormalIntegratedBC.h"

registerMooseObject("PlatypusApp", MFEMVectorNormalIntegratedBC);

InputParameters
MFEMVectorNormalIntegratedBC::validParams()
{
  InputParameters params = MFEMIntegratedBC::validParams();
  params.addClassDescription("Adds the boundary integrator to an MFEM problem for the linear form "
                             "$(\\vec f \\cdot \\hat n, v)_{\\partial\\Omega}$");
  params.addRequiredParam<std::string>(
      "vector_coefficient",
      "The vector MFEM coefficient whose normal component will be used in the integrated BC");
  return params;
}

// TODO: Currently assumes the vector function coefficient is 3D
MFEMVectorNormalIntegratedBC::MFEMVectorNormalIntegratedBC(const InputParameters & parameters)
  : MFEMIntegratedBC(parameters),
    _vec_coef_name(getParam<std::string>("vector_coefficient")),
    _vec_coef(const_cast<MFEMVectorCoefficient *>(
        &getUserObject<MFEMVectorCoefficient>("vector_coefficient")))
{
}

// Create a new MFEM integrator to apply to the RHS of the weak form. Ownership managed by the
// caller.
mfem::LinearFormIntegrator *
MFEMVectorNormalIntegratedBC::createLinearFormIntegrator()
{
  return new mfem::BoundaryNormalLFIntegrator(*_vec_coef->getVectorCoefficient());
}

// Create a new MFEM integrator to apply to LHS of the weak form. Ownership managed by the caller.
mfem::BilinearFormIntegrator *
MFEMVectorNormalIntegratedBC::createBilinearFormIntegrator()
{
  return nullptr;
}
