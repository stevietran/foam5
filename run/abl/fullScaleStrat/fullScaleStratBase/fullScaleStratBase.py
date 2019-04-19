#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May 23 22:07:08 2018

@author: stevie
"""
import pandas as pd
import os
import matplotlib.pyplot as plt
import comFuncs as cf
import numpy as np

# Some global variables
label = 'fullScaleStrat'

#######################
# DIR
#######################
# FIG
dirFig = './Figs/'+label         
# FOAM
dirFoam = './foam/'+label   
# FOAM ATM
dirFoamAtm=dirFoam + '/fullScaleStratBase/postProcessing/sampleDict/1968/'
backLabel='backField_mag(U)_k_epsilon_nut.xy'
frontLabel='frontField_mag(U)_k_epsilon_nut.xy'
midLabel='midField_mag(U)_k_epsilon_nut.xy'
#FOAM OMEGA
#dirFoamOme= dirFoam + '/757/'   
#dirFoamOmeSST= dirFoam + '/756/'   
#backLabelOme='backField_mag(U)_k_omega_nut.xy'
###########################################
# MONIN-OBUKHOV PROFILE OF VELOCITY
# TEMPERATURE, TURBULENT K AND EPSILON
# STRATIFIED CASE
##########################################
Height=30
stepHeight=0.1
# Velocity
velDir=os.path.join(dirFoam,'Vel.csv')
# Epsilon
epsDir=os.path.join(dirFoam,'Eps.csv')
# Omega
omeDir=os.path.join(dirFoam,'Ome.csv')
# ABL data
ablDir=os.path.join(dirFoam,'ablParams')
# kinetic energy
kDir=os.path.join(dirFoam,'K.csv')
# Temperature
temDir=os.path.join(dirFoam,'Tem.csv')
# write Files
cf.writeABLStable(uStar=0.074,z0=2E-4,L=16.5,temStar=0.145,temRef=33.1,zRefTem=2,velDir=velDir,EpsDir=epsDir,OmeDir=omeDir,kDir=kDir,temDir=temDir,ablDir=ablDir,Height=Height,stepHeight=stepHeight)

###############################
# PLOT PROFILE OF U, K, EPSILON
# K-EPSILON
###############################
fig,axs = plt.subplots(nrows=1, ncols=3, figsize=(6, 3))

# Monin-Obukhov profiles
moKProfiles = pd.read_csv(kDir,skiprows=0,header=None)
moVelProfiles = pd.read_csv(velDir,skiprows=0,header=None)
moEpsProfiles = pd.read_csv(epsDir,skiprows=0,header=None)
# ploting
lbMO = ['r-', 'MO']
# ploting MO profiles
cf.plot_mo_profiles([moVelProfiles,moKProfiles,moEpsProfiles],lbMO,axs,fig)

# Reading FOAM files (Modified k-epsilon)
backProfiles = pd.read_csv(os.path.join(dirFoamAtm,frontLabel),delim_whitespace=True,skiprows=0,header=None)
# ploting
lbFoam = [['b.', 'kEpsMod']]
cf.plot_foam_profiles([backProfiles],lbFoam,axs,fig)

#dirFigure=os.path.join(dirFig, label+'Profiles')
#lim=[[0,30],[0, 20],[-100,100],[1E-5,1E2]]
#cf.save_atm_profiles(dirFigure,lim,axs,fig)
#plt.close()
