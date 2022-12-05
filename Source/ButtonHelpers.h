/*
  ==============================================================================

    ButtonHelpers.h
    Created: 4 Dec 2022 4:28:54pm
    Author:  Marri Gamard

  ==============================================================================
*/

#pragma once

namespace ButtonHelpers {
    struct {
        std::string C = "scaleButton_C";
        std::string CSharp = "scaleButton_C#";
        std::string D = "scaleButton_D";
        std::string DSharp = "scaleButton_D#";
        std::string E = "scaleButton_E";
        std::string F = "scaleButton_F";
        std::string FSharp = "scaleButton_F#";
        std::string G = "scaleButton_G";
        std::string GSharp = "scaleButton_G#";
        std::string A = "scaleButton_A";
        std::string ASharp = "scaleButton_A#";
        std::string B = "scaleButton_B";
    } scaleButtonIds;

    std::vector<std::string> scaleButtonIdsVect = {
        scaleButtonIds.C,
        scaleButtonIds.CSharp,
        scaleButtonIds.D,
        scaleButtonIds.DSharp,
        scaleButtonIds.E,
        scaleButtonIds.F,
        scaleButtonIds.FSharp,
        scaleButtonIds.G,
        scaleButtonIds.GSharp,
        scaleButtonIds.A,
        scaleButtonIds.ASharp,
        scaleButtonIds.B
    };
}

