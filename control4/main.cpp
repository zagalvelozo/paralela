#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"
#include <mpi.h>

char diccionario[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void error(char *programa);
int verificar(char *);

int main(int argc, char **argv)
{

    std::string Argumento = argv[1];
    int nodo, total_cpus;
    std::string efe = "-f";
    std::string ve = "-v";
    if (Argumento == ve)
    {
        std::cout << "Leonardo Aillapan Cuellar"
                  << "\n"
                  << "Diego Pino Contreras"
                  << "\n"
                  << "Jesús Zagal Velozo"
                  << "\n";
    }
    else if (Argumento == efe)
    {
        std::string PATH = argv[2];
        std::fstream archivo(PATH);
        MPI::Init();
        MPI_Comm_size(MPI_COMM_WORLD, &total_cpus);
        MPI_Comm_rank(MPI_COMM_WORLD, &nodo);
        int inicio = (62 / total_cpus) * nodo;
        int fin = (62 / total_cpus) * (nodo + 1);
        int largo_desencriptado;
        int i, j, k, l, m, t;
        int es_entendible;
        char *mensaje = NULL;
        char *texto = NULL;
        mensaje = "1e7830e65c4b95beaf1d481b7d31fce3763dd3f96ef9406ef058081ec1a6979716dd964d22d01bbf064f1e740b7edf512f122ccd1450859f090092c7168c5a1560b15db5a0f9d0ac06241811b4a3118e54cd4ddd2f45fde5163b869295283c13b26b722bfe5f4b4e18f510b1fb99e754d9f65e65da71913bf0a89d8ea0e6318ba15fc19975c365ae12174e99283d8227fa1685f2c41da0d6afe90b41f61491bf89f03c9f057f1288bb27c189989b09d1746c038d6db523446ae6ebc621078637212d21c7b0cba0e9abcac639d6c930ade224c764d3d996b2eb3fe1b29db400bf74cc3d7d0899ad1eabdf36a3e324d66f9a69574e8bfea41611d99423a0885b70225a00fab983ce8fe064528633b21d516558bb73bb00a89484de1b47422dabc70f7a2dfaecbd35d5b2a7a7087cc041ca3a89c1a5907a7e1c16850451935ab2f5878812eba46aacbadccb34d56df2df87385a4096c4f5b5810bb09dd2028ebaecaa6f1cf801a8995bbbcfcc1fbb45ec31b71b8bd946659f33cb18f433a3bc0b2751730665553939855918941dc609b6189863d45bbf8cac4ff0a13f0156ab93022528c1abac88ec3ed3bad48d2ce732bac986c6afa027b90a8a82b6667ff38b63ba78eec2bacaf1ea8f6cecc0602af62b6f54b0e7058650827ddb66c55598022ba6d868c573594102e89f55241847b14ce54504481598bb75078875b97353549c5bbbc2c2e4daa356a66bca4004b1dcc96e450368314eaad8a264ddb8fae54e5748db9ee6f16b09f8642696fb6e987b65f394a2a731bad92843d56b84f1202d048371d3619cd15c90cdfe7547ed63f7050a8b38d84db9f86b6a3c882ba52e6dd2bdf14197e30b32910eccd7dc46a9d1d1e88879e4ad66da1e057ba8c74cc2c96fd591116139449015cb284b53556ffbacc7bd667fb4bf87523d6570fcda76bca78d8b10ab999025647ffd50c783ec7c1da921cc372493934e90fdf151cc952772f6cbbbcd77d35808267f279ce5f5936de225f16b601a855656f7a2e3336e3e31049b6e7f448655df14f099bb24224dabc52c99368c5d676af9f38e30a22a377be18dcfea8823bc41d44ed575fac902a54b231a7591d99e0af6a983502188bc35314da967479fe75ab0badbcc3b4b9e8ee25962edd9de9fe92f3ff733cc9e39a86fc6187a1fed25ed7c2c956a5f9e3094db5afa0c5b3d8d16ea56b520a764472f705b12329e630b923741306b361896c623a698199320b91d25d7e162596b04a9af1d78c1a2825e6a54b214238efe46d59eea37acddceac6945f21dd055f467d111a9a5793f3540528c9b50d26ac3a13e6ca44168770e51bf0758242431dcdb6822b5959a35cf784386a99875d6b43f09060bf0d5e014e40dec6d2789aaae9a80c584023327fadfded557cd91ae702ecfe9e01c379be89b77a5e9b13b7ed8175c4ae3dccebdb59aa89749cce306b209c571931cf2a31f582902ae6080d61e072f2d850b0eb59a695e96d4d93a7f0e712383c7954598eee6c3f55e5516fac09cff56d5aa456eed947109dcd51735f87231c74e498faf9a9a1af83eb4808caca33422b5f39acbd6d6e9e3f2b07ff9e3fc5604bae981a404eaa06009ae13ede80f83907a1c9169cafabea66a017dd8cb5ec23a0e4985b89091d83bf42806d83ab8049b1a18672ddaa89562e32250bb47c764a907f79732a8196fc81ae024f1791b38f6144588527cfeab919982a69a98feec787d705e6ec906b869e2294b1ebac67d4559ad31ac7df5bec34db39e16b555162cfede1697476b5e0dc44525d8fae5cd6312185188b747f8ccb5ba2df50fdd0b606a0d3fdb1805f5d7e8d35a6c0bb9c72f487aa7d84e2e8e0a666f8950379fa12fb11b556bac4ff4d9fb2a04979ed138f0356af55e85828eb69706d5597bc0f238cb1244851764db534ec251dfb2e970e8c73ee42f0f0b0592848eacda68a483ff1fbe045844205c204bfe9084d836a33df2aaa88763f69a9590c2757ff0c1c4328a02744eae247c4ca47c6d67ed7ad99af527351b41e51254acddaf5a12a9c001e79e99e9b2220bdf0519a9fa17459e78b4eb15658254331f76074e36ddfe4ea75a7baaeeefcd67d09ed8dadc7c31b68d876d63ac47e2223b225b0667731a44f06164388c8c2bcf212bf00ecac9b1f45a2d5723f9e86416be45e24d982be9180fc99bd6e901f83694915caeba73a93d23c7017660d8ef63e4e1bb959b4e8cc8200489cdf7eb9af3ee20a42ebec988ab4ebb42731d658ce9101d22f24a0dfb6fa4f6879d2c1bae12363cdf6a11bc21048f801951b74e3befe9ba931e5d2d5b156cdea719fc30968a60b7d6e094b84acecece7c38106807a522d906e5c8e87f75c566abdce3895c0f6706b064eb1eb66b9f2afd06471a0d998549b395a92fc8fc";
        char palabra[6]; //palabra de seis digitos
        for (i = inicio; i < fin; i++)
        { //ciclo repetir para ir sacando las posibles combinaciones teniendo 62 posibilidades de cada digito
            for (j = 0; j < 62; j++)
            {
                for (k = 0; k < 62; k++)
                {
                    for (l = 0; l < 62; l++)
                    {
                        for (m = 0; m < 62; m++)
                        {
                            for (t = 0; t < 62; t++)
                            {
                                free(texto);
                                palabra[0] = diccionario[i];
                                palabra[1] = diccionario[j];
                                palabra[2] = diccionario[k];
                                palabra[3] = diccionario[l];
                                palabra[4] = diccionario[m];
                                palabra[5] = diccionario[t];
                                std::cout << palabra << std::endl;
                                texto = descifrar(palabra, mensaje);
                                largo_desencriptado = strlen(texto);
                                es_entendible = verificar(texto);
                                if (es_entendible == 1)
                                {

                                    if (largo_desencriptado > 8)
                                    {
                                        archivo << texto;
                                        archivo << " \n";
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        archivo.close();
        std::cout << "done!\n";
        MPI::Finalize();
    }
    return 0;
}

int verificar(char mensaje[])
{
    int i;
    int largo;
    int caracter;
    int ver;

    largo = strlen(mensaje);

    for (i = 0; i < largo; i++)
    {
        caracter = (int)mensaje[i];
        if ((caracter >= 32) && (caracter <= 127))
        {
            ver = 1;
        }
        else
        {

            return 0;
        }
    }
    return 1;
}
