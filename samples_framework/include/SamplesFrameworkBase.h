/***********************************************************************
    filename:   SamplesFrameworkBase.h
    created:    24/9/2004
    author:     Paul D Turner
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _SamplesFrameworkBase_h_
#define _SamplesFrameworkBase_h_

// forward declarations
class CEGuiBaseApplication;
class CEGuiRendererSelector;

#include "CEGUI/InputEvent.h"

/*!
\brief
    This is a base class that is intended to be used for all sample applications.
    Here we take care of common things such the renderer selection and application
    startup.
*/
class SamplesFrameworkBase
{
public:
    /*!
    \brief
        Constructor.
    */
    SamplesFrameworkBase();


    /*!
    \brief
        Destructor.
    */
    virtual ~SamplesFrameworkBase();


    /*!
    \brief
        Application entry point.

    \return
        code to be returned by the application.
    */
    int run();


    /*!
    \brief
        Sample specific initialisation goes here.  This method is called by the application base object created
        as part of the initialise call.

    \return
        false if something went wrong.
    */
    virtual bool initialiseSample()  = 0;


    /*!
    \brief
        Cleans up resources allocated in the initialiseSample call.
    */
    virtual void cleanupSample() = 0;

    /*!
    \brief
        Update function called before rendering
    */
    virtual void update(float passedTime) = 0;

    /*!
    \brief
    Update function for window size changes
    */
    virtual void handleNewWindowSize(float width, float height) = 0;

    /*!
    \brief
    Draw function to draw GUIContexts
    */
    virtual void drawGUIContexts() = 0;

    /*!
    \brief
    Function to inject key down to GUIContexts
    */
    virtual void injectKeyDown(const CEGUI::Key::Scan& ceguiKey) = 0;

    /*!
    \brief
    Function to inject key up to GUIContexts
    */
    virtual void injectKeyUp(const CEGUI::Key::Scan& ceguiKey) = 0;

    /*!
    \brief
    Function to inject characters to GUIContexts
    */
    virtual void injectChar(int character) = 0;

    /*!
    \brief
    Function to inject mouse button down to GUIContexts
    */
    virtual void injectMouseButtonDown(const CEGUI::MouseButton& ceguiMouseButton) = 0;

    /*!
    \brief
    Function to inject mouse button up to GUIContexts
    */
    virtual void injectMouseButtonUp(const CEGUI::MouseButton& ceguiMouseButton) = 0;

    /*!
    \brief
    Function to inject mouse wheel changes to GUIContexts
    */
    virtual void injectMouseWheelChange(float position) = 0;

    /*!
    \brief
    Function to inject the mouse position to GUIContexts
    */
    virtual void injectMousePosition(float x, float y) = 0;

protected:
    /*!
    \brief
        Initialises the sample system, this includes asking the user for a render to use and
        the subsequent creation of the required systems to support that renderer.

    \return
        false if anything went wrong.
    */
    virtual bool initialise();


    /*!
    \brief
        Cleans up all resources allocated by the initialise call.
    */
    virtual void cleanup();


    /*!
    \brief
        Output a message to the user in some OS independant way.
    */
    static void outputExceptionMessage(const char* message);

    /*************************************************************************
        Data fields
    *************************************************************************/
    CEGuiRendererSelector*  d_rendererSelector;     //!< Points to the renderer selector object.
    CEGuiBaseApplication*   d_sampleApp;            //!< Pointer to the base application object.
};

#endif  // end of guard _SamplesFrameworkBase_h_