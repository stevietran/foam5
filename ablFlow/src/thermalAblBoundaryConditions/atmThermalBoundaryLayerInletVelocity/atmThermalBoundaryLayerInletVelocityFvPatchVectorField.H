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

Class
    Foam::atmThermalBoundaryLayerInletVelocityFvPatchVectorField

Group
    grpRASBoundaryConditions grpInletBoundaryConditions

Description
    This boundary condition specifies a velocity inlet profile appropriate
    for atmospheric boundary layers (ABL).

    See Foam::atmThermalBoundaryLayer for details.

    Example of the boundary condition specification:
    \verbatim
    ground
    {
        type            atmThermalBoundaryLayerInletVelocity;
        n               (1 0 0);
        z               (0 0 1);
        Uref            10.0;
        Zref            20.0;
        z0              uniform 0.1;
        zGround         uniform 0.0;
    }
    \endverbatim

See also
    Foam::atmThermalBoundaryLayer,
    Foam::atmThermalBoundaryLayerInletKFvPatchScalarField,
    Foam::atmThermalBoundaryLayerInletEpsilonFvPatchScalarField

SourceFiles
    atmThermalBoundaryLayerInletVelocityFvPatchVectorField.C

\*---------------------------------------------------------------------------*/

#ifndef atmThermalBoundaryLayerInletVelocityFvPatchVectorField_H
#define atmThermalBoundaryLayerInletVelocityFvPatchVectorField_H

#include "fvPatchFields.H"
#include "fixedValueFvPatchFields.H"
#include "atmThermalBoundaryLayer.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
       Class atmThermalBoundaryLayerInletVelocityFvPatchVectorField Declaration
\*---------------------------------------------------------------------------*/

class atmThermalBoundaryLayerInletVelocityFvPatchVectorField
:
    public fixedValueFvPatchVectorField,
    public atmThermalBoundaryLayer
{

public:

    //- Runtime type information
    TypeName("atmThermalBoundaryLayerInletVelocity");


    // Constructors

        //- Construct from patch and internal field
        atmThermalBoundaryLayerInletVelocityFvPatchVectorField
        (
            const fvPatch&,
            const DimensionedField<vector, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        atmThermalBoundaryLayerInletVelocityFvPatchVectorField
        (
            const fvPatch&,
            const DimensionedField<vector, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given
        // atmThermalBoundaryLayerInletVelocityFvPatchVectorField onto a new patch
        atmThermalBoundaryLayerInletVelocityFvPatchVectorField
        (
            const atmThermalBoundaryLayerInletVelocityFvPatchVectorField&,
            const fvPatch&,
            const DimensionedField<vector, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchVectorField> clone() const
        {
            return tmp<fvPatchVectorField>
            (
                new atmThermalBoundaryLayerInletVelocityFvPatchVectorField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        atmThermalBoundaryLayerInletVelocityFvPatchVectorField
        (
            const atmThermalBoundaryLayerInletVelocityFvPatchVectorField&,
            const DimensionedField<vector, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchVectorField> clone
        (
            const DimensionedField<vector, volMesh>& iF
        ) const
        {
            return tmp<fvPatchVectorField>
            (
                new atmThermalBoundaryLayerInletVelocityFvPatchVectorField(*this, iF)
            );
        }


    // Member functions

        // Mapping functions

            //- Map (and resize as needed) from self given a mapping object
            virtual void autoMap
            (
                const fvPatchFieldMapper&
            );

            //- Reverse map the given fvPatchField onto this fvPatchField
            virtual void rmap
            (
                const fvPatchVectorField&,
                const labelList&
            );


        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
