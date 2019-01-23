/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "atmThermalBoundaryLayerInletKFvPatchScalarField.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

atmThermalBoundaryLayerInletKFvPatchScalarField::
atmThermalBoundaryLayerInletKFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(p, iF),
    atmThermalBoundaryLayer()
{}


atmThermalBoundaryLayerInletKFvPatchScalarField::
atmThermalBoundaryLayerInletKFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchScalarField(p, iF, dict, false),
    atmThermalBoundaryLayer(patch().Cf(), dict)
{
    scalarField::operator=(k(patch().Cf()));
}


atmThermalBoundaryLayerInletKFvPatchScalarField::
atmThermalBoundaryLayerInletKFvPatchScalarField
(
    const atmThermalBoundaryLayerInletKFvPatchScalarField& psf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchScalarField(psf, p, iF, mapper),
    atmThermalBoundaryLayer(psf, mapper)
{}


atmThermalBoundaryLayerInletKFvPatchScalarField::
atmThermalBoundaryLayerInletKFvPatchScalarField
(
    const atmThermalBoundaryLayerInletKFvPatchScalarField& psf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(psf, iF),
    atmThermalBoundaryLayer(psf)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void atmThermalBoundaryLayerInletKFvPatchScalarField::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchScalarField::autoMap(m);
    atmThermalBoundaryLayer::autoMap(m);
}


void atmThermalBoundaryLayerInletKFvPatchScalarField::rmap
(
    const fvPatchScalarField& psf,
    const labelList& addr
)
{
    fixedValueFvPatchScalarField::rmap(psf, addr);

    const atmThermalBoundaryLayerInletKFvPatchScalarField& blpsf =
        refCast<const atmThermalBoundaryLayerInletKFvPatchScalarField>(psf);

    atmThermalBoundaryLayer::rmap(blpsf, addr);
}


void atmThermalBoundaryLayerInletKFvPatchScalarField::write(Ostream& os) const
{
    fvPatchScalarField::write(os);
    atmThermalBoundaryLayer::write(os);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makePatchTypeField
(
    fvPatchScalarField,
    atmThermalBoundaryLayerInletKFvPatchScalarField
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
