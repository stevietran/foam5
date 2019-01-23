/*--------------------------------*- C++ -*----------------------------------*\
| =========                 |                                                 |
| \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |
|  \\    /   O peration     | Version:  2.1.0                                 |
|   \\  /    A nd           | Web:      www.OpenFOAM.org                      |
|    \\/     M anipulation  |                                                 |
\*---------------------------------------------------------------------------*/
FoamFile
{
    version     2.0;
    format      ascii;
    class       dictionary;
    object      blockMeshDict;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
dnl> -----------------------------------------------------------------
dnl> <STANDARD DEFINTIONS>
dnl>
changecom(//)changequote([,]) dnl>
define(calc, [esyscmd(perl -e 'print ($1)')]) dnl>
define(VCOUNT, 0)  dnl>
define(vlabel, [[// ]pt VCOUNT ($1) define($1, VCOUNT)define([VCOUNT], incr(VCOUNT))])  dnl>
dnl>
define(hex2D, hex ($1b $2b $3b $4b $1t $2t $3t $4t)) dnl>
define(quad2D, ($1b $2b $2t $1t))dnl>
define(frontQuad, ($1t $2t $3t $4t))dnl>
define(backQuad, ($1b $4b $3b $2b))dnl>
dnl>
define(d, 25) dnl>
define(AR, 20) dnl>
dnl>
define(x0,calc(d*(-6.)))dnl>
define(x3,calc(d*34.))dnl>
dnl>
define(y0, 0.0)dnl>
define(y2,calc(d*12.))dnl>
dnl>
define(z0, 0.0)dnl>
define(z1,calc(d*2.0)) dnl>
dnl>
define(nCell, calc(d/2.5)) dnl>
dnl>
define(nAxial, calc(int((int(x3)-int(x0))/nCell))) dnl>
define(AxialGrade, 1) dnl>
dnl>
define(nRad, calc(int((y2-y0)/nCell))) dnl>
define(RadGrade, 1) dnl>
dnl>
define(nCellHigh,calc(nCell/AR)) dnl>
define(cellRatio, 1.075)
define(nHigh, calc(int(log((cellRatio-1)*(z1-z0)/nCellHigh+1)/log(cellRatio)))) dnl>
define(highGrade,calc(cellRatio**(nHigh-1)))
dnl>

convertToMeters 1;
vertices
(
    (x0   y0    z0)   vlabel(a1b)
    (x3   y0      z0)    vlabel(a4b)
    (x0   y2      z0)    vlabel(c1b)
    (x3   y2      z0)    vlabel(c4b)

    (x0   y0    z1)   vlabel(a1t)
    (x3   y0      z1)    vlabel(a4t)
    (x0   y2      z1)    vlabel(c1t)
    (x3   y2      z1)    vlabel(c4t)
);

blocks
(
    // Front block
    hex2D(a1, a4, c4, c1) 
    ( nAxial nRad nHigh )  
    simpleGrading
    (
        1
        1
        highGrade
    )
);

edges
(
);

boundary
(
    frontField
    {
        type patch;
        faces
        (
            quad2D(c1, a1)
        );
    }
    backField
    {
        type patch;
        faces
        (
            quad2D(c4, a4)
        );
    }
    symPlane
    {
        type symmetryPlane;
        faces
        (
            quad2D(a1, a4)
        );
    }
    sideField
    {
        type patch;
        faces
        (
            quad2D(c4, c1)
        );
    }
    ground
    {
        type wall;
        faces
        (
            backQuad(a4, a1, c1, c4)
	    );
    }        
    top
    {
        type patch;
        faces
        (
            frontQuad(a1, a4, c4, c1)
	    );
    }        
);

mergePatchPairs
(
);

// ************************************************************************* //
