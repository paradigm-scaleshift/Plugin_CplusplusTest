/* ValueTransform_Plugin - for licensing and copyright see license.txt */

#include <StdAfx.h>
#include <CPluginCplusplusTest.h>

#include <Nodes/G2FlowBaseNode.h>

#include <Game.h>

namespace CplusplusTestPlugin
{
    class CFlowPrimeCheckNode :
        public CFlowBaseNode<eNCT_Instanced>
    {
        private:

            enum EInputPorts
            {
                EIP_VALUE = 0,
                EIP_INDEX = 0,
            };

            enum EOutputPorts
            {
                EOP_VALUE = 0,
                EOP_PRIME,
            };

        public:

            CFlowPrimeCheckNode( SActivationInfo* pActInfo )
            {
            }


            //Check Prime function
            int checkPrime( int value )

            {

                int result = 0;
                int testNo = value;
                int resultArray[100];

                do
                {
					if ( value % testNo == 0 )
                    {
						resultArray[result] = testNo;
                        result ++;
						}
				testNo--;
                }
                while ( testNo > 0 );

                for ( int x = 0; x < result; x++ )
                {

                }

                return result;

            }


            virtual void GetMemoryUsage( ICrySizer* s ) const
            {
                s->Add( *this );
            }

            virtual IFlowNodePtr Clone( SActivationInfo* pActInfo )
            {
                return new CFlowPrimeCheckNode( pActInfo );
            }

            virtual ~CFlowPrimeCheckNode()
            {

            }

            virtual void GetConfiguration( SFlowNodeConfig& config )
            {
                static const SInputPortConfig inputs[] =
                {

                    InputPortConfig<float>( "Value", 0, _HELP( "Value" ) ),
                    InputPortConfig<float>( "index", 0, _HELP( "index" ) ),
                    InputPortConfig_Null(),
                };

                static const SOutputPortConfig outputs[] =
                {
                    OutputPortConfig<float>( "Value", _HELP( "Value" ) ),
                    OutputPortConfig<bool>( "prime", _HELP( "Prime?" ) ),
                    OutputPortConfig_Null(),
                };

                config.pInputPorts = inputs;
                config.pOutputPorts = outputs;
                config.sDescription = _HELP( "PrimeCheck" );

                config.SetCategory( EFLN_APPROVED );
            }

            virtual void ProcessEvent( EFlowEvent evt, SActivationInfo* pActInfo )
            {
                switch ( evt )
                {
                    case eFE_Suspend:
                        break;

                    case eFE_Resume:
                        break;

                    case eFE_Activate:
                        if ( IsPortActive( pActInfo, EIP_VALUE ) )
                        {
                            float fValue = GetPortFloat( pActInfo, EIP_VALUE );
                            float fIndex = GetPortFloat( pActInfo, EIP_INDEX );

                            fValue = checkPrime( fValue );

                            ActivateOutput<float>( pActInfo, EOP_VALUE, float( fValue ) );


                            if ( fValue < 5 )
                            {
                                ActivateOutput<bool>( pActInfo, EOP_PRIME, bool( 1 ) );
                            }

                            else
                            {
                                ActivateOutput<bool>( pActInfo, EOP_PRIME, bool( 0 ) );
                            }

                        }

                        break;

                    case eFE_SetEntityId:
                        //m_pEntity = pActInfo->pEntity;
                        break;

                    case eFE_Update:
                        break;
                }
            }
    };
}

REGISTER_FLOW_NODE_EX( "CplusplusTest:PrimeCheck", CplusplusTestPlugin::CFlowPrimeCheckNode, CFlowPrimeCheckNode );