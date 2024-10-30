////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Logging.hpp>
#include <yq/core/LogFilter.hpp>

#define glfwAlert                   yAlert("glfw")
#define glfwCritical                yCritical("glfw")
#define glfwDebug                   yDebug("glfw")
#define glfwError                   yError("glfw")
#define glfwEmergency               yEmergency("glfw")
#define glfwFatal                   yFatal("glfw")
#define glfwInfo                    yInfo("glfw")
#define glfwNotice                  yNotice("glfw")
#define glfwWarning                 yWarning("glfw")

#define imguiAlert                  yAlert("imgui")
#define imguiCritical               yCritical("imgui")
#define imguiDebug                  yDebug("imgui")
#define imguiError                  yError("imgui")
#define imguiEmergency              yEmergency("imgui")
#define imguiFatal                  yFatal("imgui")
#define imguiInfo                   yInfo("imgui")
#define imguiNotice                 yNotice("imgui")
#define imguiWarning                yWarning("imgui")

#define tachyonAlert                yAlert("tachyon")
#define tachyonCritical             yCritical("tachyon")
#define tachyonDebug                yDebug("tachyon")
#define tachyonError                yError("tachyon")
#define tachyonEmergency            yEmergency("tachyon")
#define tachyonFatal                yFatal("tachyon")
#define tachyonInfo                 yInfo("tachyon")
#define tachyonNotice               yNotice("tachyon")
#define tachyonWarning              yWarning("tachyon")

#define vizAlert                    yAlert("viz")
#define vizCritical                 yCritical("viz")
#define vizDebug                    yDebug("viz")
#define vizError                    yError("viz")
#define vizEmergency                yEmergency("viz")
#define vizFatal                    yFatal("viz")
#define vizInfo                     yInfo("viz")
#define vizNotice                   yNotice("viz")
#define vizWarning                  yWarning("viz")

#define vizFirstAlert(...)          yLogFirstAlert("viz", __VA_ARGS__)
#define vizFirstCritical(...)       yLogFirstCritical("viz", __VA_ARGS__)
#define vizFirstDebug(...)          yLogFirstDebug("viz", __VA_ARGS__)
#define vizFirstError(...)          yLogFirstError("viz", __VA_ARGS__)
#define vizFirstEmergency(...)      yLogFirstEmergency("viz", __VA_ARGS__)
#define vizFirstFatal(...)          yLogFirstFatal("viz", __VA_ARGS__)
#define vizFirstInfo(...)           yLogFirstInfo("viz", __VA_ARGS__)
#define vizFirstNotice(...)         yLogFirstNotice("viz", __VA_ARGS__)
#define vizFirstWarning(...)        yLogFirstWarning("viz", __VA_ARGS__)

#define vizOnceAlert                yLogOnceAlert("viz")             
#define vizOnceCritical             yLogOnceCritical("viz")          
#define vizOnceDebug                yLogOnceDebug("viz")             
#define vizOnceError                yLogOnceError("viz")             
#define vizOnceEmergency            yLogOnceEmergency("viz")         
#define vizOnceFatal                yLogOnceFatal("viz")             
#define vizOnceInfo                 yLogOnceInfo("viz")              
#define vizOnceNotice               yLogOnceNotice("viz")            
#define vizOnceWarning              yLogOnceWarning("viz")           

#define vqAlert                     yAlert("vq")
#define vqCritical                  yCritical("vq")
#define vqDebug                     yDebug("vq")
#define vqError                     yError("vq")
#define vqEmergency                 yEmergency("vq")
#define vqFatal                     yFatal("vq")
#define vqInfo                      yInfo("vq")
#define vqNotice                    yNotice("vq")
#define vqWarning                   yWarning("vq")

#define vqFirstAlert(...)           yLogFirstAlert("vq", __VA_ARGS__)
#define vqFirstCritical(...)        yLogFirstCritical("vq", __VA_ARGS__)
#define vqFirstDebug(...)           yLogFirstDebug("vq", __VA_ARGS__)
#define vqFirstError(...)           yLogFirstError("vq", __VA_ARGS__)
#define vqFirstEmergency(...)       yLogFirstEmergency("vq", __VA_ARGS__)
#define vqFirstFatal(...)           yLogFirstFatal("vq", __VA_ARGS__)
#define vqFirstInfo(...)            yLogFirstInfo("vq", __VA_ARGS__)
#define vqFirstNotice(...)          yLogFirstNotice("vq", __VA_ARGS__)
#define vqFirstWarning(...)         yLogFirstWarning("vq", __VA_ARGS__)
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Logging.hpp>

#define glfwAlert           yAlert("glfw")
#define glfwCritical        yCritical("glfw")
#define glfwDebug           yDebug("glfw")
#define glfwError           yError("glfw")
#define glfwEmergency       yEmergency("glfw")
#define glfwFatal           yFatal("glfw")
#define glfwInfo            yInfo("glfw")
#define glfwNotice          yNotice("glfw")
#define glfwWarning         yWarning("glfw")
