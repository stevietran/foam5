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

#include "atmThermalBoundaryLayerInletVelocityFvPatchVectorField.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

atmThermalBoundaryLayerInletVelocityFvPatchVectorField::
atmThermalBoundaryLayerInletVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(p, iF),
    atmThermalBoundaryLayer()
{}


atmThermalBoundaryLayerInletVelocityFvPatchVectorField::
atmThermalBoundaryLayerInletVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchVectorField(p, iF, dict, false),
    atmThermalBoundaryLayer(patch().Cf(), dict)
{
    vectorField::operator=(U(patch().Cf()));
}


atmThermalBoundaryLayerInletVelocityFvPatchVectorField::
atmThermalBoundaryLayerInletVelocityFvPatchVectorField
(
    const atmThermalBoundaryLayerInletVelocityFvPatchVectorField& pvf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchVectorField(pvf, p, iF, mapper),
    atmThermalBoundaryLayer(pvf, mapper)
{}


atmThermalBoundaryLayerInletVelocityFvPatchVectorField::
atmThermalBoundaryLayerInletVelocityFvPatchVectorField
(
    const atmThermalBoundaryLayerInletVelocityFvPatchVectorField& pvf,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(pvf, iF),
    atmThermalBoundaryLayer(pvf)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void atmThermalBoundaryLayerInletVelocityFvPatchVectorField::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchVectorField::autoMap(m);
    atmThermalBoundaryLayer::autoMap(m);
}


void atmThermalBoundaryLayerInletVelocityFvPatchVectorField::rmap
(
    const fvPatchVectorField& pvf,
    const labelList& addr
)
{
    fixedValueFvPatchVectorField::rmap(pvf, addr);

    const atmThermalBoundaryLayerInletVelocityFvPatchVectorField& blpvf =
        refCast<const atmThermalBoundaryLayerInletVelocityFvPatchVectorField>(pvf);

    atmThermalBoundaryLayer::rmap(blpvf, addr);
}


void atmThermalBoundaryLayerInletVelocityFvPatchVectorField::write(Ostream& os) const
{
    fvPatchVectorField::write(os);
    atmThermalBoundaryLayer::write(os);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makePatchTypeField
(
    fvPatchVectorField,
    atmThermalBoundaryLayerInletVelocityFvPatchVectorField
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
