/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** DatabasesSqlite
*/


#ifndef DATABASESSQLITE_HPP_
    #define DATABASESSQLITE_HPP_
    #include <iostream>
    #include <SQLiteCpp/SQLiteCpp.h>
    #include <iostream>
    #include <fstream>
    #include <Client.hpp>
    #include "Contacts.hpp"


namespace Server
{

    static const std::string DATABASE_PATH = "../db/database.db";



    class SQLiteDatabase {
        public:
            SQLiteDatabase(const std::string& path) : dbPath(path) {
                if (!isDatabaseExists()) {
                    createDatabase();
                }
            }

            SQLiteDatabase(): dbPath(DATABASE_PATH) {
                if (!isDatabaseExists()) {
                    createDatabase();
                }
            }

            SQLiteDatabase() = default;

            ~SQLiteDatabase() = default;

            std::vector<Client> getUsers() {
                std::vector<Client> users;
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE);
                    SQLite::Statement query(db, "SELECT * FROM users");
                    while (query.executeStep()) {
                        Client user;
                        user.setId(query.getColumn("id"));
                        user.setUsername(query.getColumn("username"));
                        user.setPassword(query.getColumn("password"));
                        users.push_back(user);
                    }
                } catch (std::exception& e) {
                    std::cerr << "Erreur lors de la récupération des utilisateurs : " << e.what() << std::endl;
                }
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE);
                    SQLite::Statement query(db, "SELECT * FROM contacts");
                    SQLite::Statement contacts_query(db, "SELECT * FROM users");
                    size_t id_temp = 0;
                    std::string username_temp = "";
                    size_t status_temp = 0;
                    for (auto &i : users) {
                        while (query.executeStep()) {
                            if (i.getId() == query.getColumn("id_user")) {

                                status_temp = query.getColumn("status");
                                id_temp = query.getColumn("id_contact");
                                while (contacts_query.executeStep()) {
                                    if (id_temp == contacts_query.getColumn("id")) {
                                        username_temp = contacts_query.getColumn("username");
                                        break;
                                    }
                                }
                                i.addContact(Contacts(username_temp, id_temp, status_temp);
                            }
                        }
                    }
                } catch (std::exception& e) {
                    std::cerr << "Erreur lors de la récupération des utilisateurs : " << e.what() << std::endl;
                }


                return users;
            }

            

        private:
            // Vérifier si la base de données existe
            bool isDatabaseExists() {
                std::ifstream file(dbPath.c_str());
                return file.good();
            }

            // Créer la base de données et écrire les schémas SQL
            void createDatabase() {
            try {
                SQLite::Database db(dbPath, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

                // Écrivez ici vos schémas SQL
                db.exec("CREATE TABLE IF NOT EXISTS users ("
                    "id INTEGER PRIMARY KEY, "
                    "username TEXT, "
                    "password TEXT, "
                    "updated_at DATETIME, "
                    "created_at DATETIME);");

            // Création de la table 'contacts'
                db.exec("CREATE TABLE IF NOT EXISTS contacts ("
                    "id INTEGER PRIMARY KEY, "
                    "id_user INTEGER, "
                    "id_contact INTEGER, "
                    "updated_at DATETIME, "
                    "created_at DATETIME, "
                    "FOREIGN KEY(id_user) REFERENCES users(id));");

                std::cout << "Base de données créée avec succès." << std::endl;
            } catch (std::exception& e) {
                std::cerr << "Erreur lors de la création de la base de données : " << e.what() << std::endl;
            }
        }



    private:
        std::string dbPath;
    };


    
} // namespace Server



#endif /* !DATABASESSQLITE_HPP_ */
