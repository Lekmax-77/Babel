
                    /*
                    void startAsyncInput()
                    {
                        asyncInputTimer_ = std::make_shared<asio::steady_timer>(*iocontext_);
                        asyncInputTimer_->expires_after(std::chrono::milliseconds(100)); // Vérification toutes les 100 millisecondes
                        asyncInputTimer_->async_wait([this](const boost::system::error_code &ec) { handleAsyncInput(ec); });
                    }


                    void handleAsyncInput(const boost::system::error_code &ec)
                    {
                        if (!ec)
                        {
                            std::string input;
                            std::cout << "&> ";
                            std::getline(std::cin, input);

                            if (input == "exit")
                            {
                                // Fermer toutes les connexions et arrêter le serveur
                                iocontext_->post([this]()
                                                 {
                                                     for (auto &client : clients_)
                                                     {
                                                         client->disconnect();
                                                     }
                                                     clients_.clear();
                                                     acceptor_.close();
                                                 });
                            }
                            else
                            {
                                // Envoyer le message à tous les clients
                                iocontext_->post([this, input]()
                                                 {
                                                     for (auto &client : clients_)
                                                     {
                                                         client->doSend(input);
                                                     }
                                                 });

                                // Relancer la vérification de la saisie asynchrone
                                asyncInputTimer_->expires_after(std::chrono::milliseconds(100));
                                asyncInputTimer_->async_wait([this](const boost::system::error_code &ec) { handleAsyncInput(ec); });
                            }
                        }
                    }


                    
                    void startConsoleInput(asio::io_context &ioContext)
                    {
                        std::thread([this, &ioContext]()
                                    {
                                        while (true)
                                        {
                                            std::string input;
                                            std::cout << "&> ";
                                            std::getline(std::cin, input);

                                            if (input == "exit")
                                            {
                                                // Fermer toutes les connexions et arrêter le serveur
                                                ioContext.post([this]()
                                                               {
                                                                   for (auto &client : clients_)
                                                                   {
                                                                       client->disconnect();
                                                                   }
                                                                   clients_.clear();
                                                                   acceptor_.close();
                                                               });
                                                break;
                                            }

                                            // Envoyer le message à tous les clients
                                            ioContext.post([this, input]()
                                                           {
                                                               for (auto &client : clients_)
                                                               {
                                                                   client->doWrite(input);
                                                               }
                                                           });
                                        }
                                    })
                            .detach();
                    }
                    */
                private: