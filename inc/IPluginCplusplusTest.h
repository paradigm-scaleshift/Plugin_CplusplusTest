/* CplusplusTest_Plugin - for licensing and copyright see license.txt */

#include <IPluginBase.h>

#pragma once

/**
* @brief CplusplusTest Plugin Namespace
*/
namespace CplusplusTestPlugin
{
    /**
    * @brief plugin CplusplusTest concrete interface
    */
    struct IPluginCplusplusTest
    {
        /**
        * @brief Get Plugin base interface
        */
        virtual PluginManager::IPluginBase* GetBase() = 0;

        // TODO: Add your concrete interface declaration here
    };
};