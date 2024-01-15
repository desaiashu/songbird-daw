/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <juce_core/juce_core.h>

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    setSize (800, 600); // Set a larger size for the editor to accommodate the browser

    addAndMakeVisible(browser); // Make the browser visible in this component
//    browser.goToURL("https://dev.808gpt.xyz"); // Load a webpage
    
    juce::File htmlFile = juce::File::getSpecialLocation(juce::File::currentExecutableFile).getParentDirectory().getParentDirectory().getChildFile("Resources/index.html");
    
    DBG("Your log message here");
    DBG(htmlFile.getFullPathName());
    
    juce::Logger::writeToLog("dfasdfasdfasdfsad");
    
    std::cout << "ASHU";
    
    if (htmlFile.exists())
    {
        juce::URL localHtmlUrl = juce::URL(htmlFile);
        browser.goToURL(localHtmlUrl.toString(false));
    }
    else
    {
        // Handle the error in case the file does not exist
        browser.goToURL("https://studiocollective.xyz");
    }
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    browser.setBounds(getLocalBounds());
}
