// This file has been generated by Py++.

#include "boost/python.hpp"

#include "python_CEGUIOpenGLRenderer.h"

#include "OpenGLRenderer.pypp.hpp"

#include "OpenGLTextureTarget.pypp.hpp"

#include "OpenGLViewportTarget.pypp.hpp"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(PyCEGUIOpenGLRenderer){
    register_OpenGLRenderer_class();

    register_OpenGLTextureTarget_class();

    boost::python::scope().attr("CompileDate__") = __DATE__;

    boost::python::scope().attr("CompileTime__") = __TIME__;

    boost::python::scope().attr("__doc__") = "PyCEGUIOpenGLRenderer - version 0.8.9090";

    boost::python::scope().attr("Version__") = "0.8.9090";

    register_OpenGLViewportTarget_class();
}
