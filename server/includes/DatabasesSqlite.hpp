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
#include "../../common/Client.hpp"
#include <vector>

namespace Babel::Server
{

    static const std::string ABS_PATH = std::filesystem::absolute("server/db/database.sqlite").string();




    class SQLiteDatabase {
        public:
            SQLiteDatabase(const std::string& path) : dbPath(path) {
                if (!isDatabaseExists()) {
                    createDatabase();
                }
            }

            SQLiteDatabase(): dbPath(ABS_PATH) {
                if (!isDatabaseExists()) {
                    createDatabase();
                }
            }

            ~SQLiteDatabase() = default;

            std::vector<Babel::Client_Data> getUsers()
            {
                std::vector<Babel::Client_Data> users;
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE);
                    SQLite::Statement query(db, "SELECT * FROM users");
                    while (query.executeStep()) {
                        Babel::Client_Data user;
                        size_t id_user_temp = query.getColumn(0).getInt();
                        user.setId(id_user_temp);
                        user.setUsername(query.getColumn(1).getText());
                        user.setPassword(query.getColumn(2).getText());
                        //continue
                        users.push_back(user);
                    }
                    query.reset();
                } catch (std::exception& e) {
                    std::cerr << "Error of Query users : " << e.what() << std::endl;
                }

                return users;
            }

            // Méthode pour insérer un nouvel utilisateur dans la base de données
            std::vector<Babel::Client_Data> insertUser(const Babel::Client_Data& user)
            {
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE);
                    SQLite::Statement query(db,
                                            "INSERT INTO users (username, password, updated_at, created_at) VALUES (?, ?, DATETIME('now'), DATETIME('now'))");

                    query.bind(1, user.getUsername());
                    query.bind(2, user.getPassword());

                    query.exec();
                } catch (std::exception& e) {
                    std::cerr << "Error inserting user: " << e.what() << std::endl;
                }
                return getUsers();
            }

            // Méthode pour mettre à jour les informations d'un utilisateur dans la base de données
            std::vector<Babel::Client_Data> updateUser(const Babel::Client_Data& user)
            {
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE);
                    SQLite::Statement query(db,
                                            "UPDATE users SET username = ?, password = ?, updated_at = DATETIME('now') WHERE id = ?");

                    query.bind(1, user.getUsername());
                    query.bind(2, user.getPassword());
                    query.bind(3, static_cast<int>(user.getId()));

                    query.exec();
                } catch (std::exception& e) {
                    std::cerr << "Error updating user: " << e.what() << std::endl;
                }
                return getUsers();
            }

            // Méthode pour supprimer un utilisateur de la base de données
            std::vector<Babel::Client_Data> deleteUser(std::size_t userId)
            {
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE);
                    SQLite::Statement query(db, "DELETE FROM users WHERE id = ?");

                    query.bind(1, static_cast<int>(userId));

                    query.exec();
                } catch (std::exception& e) {
                    std::cerr << "Error deleting user: " << e.what() << std::endl;
                }
                return getUsers();
            }



        private:
            bool isDatabaseExists() {
                std::ifstream file(dbPath.c_str());
                return file.good();
            }

            void createDatabase() {
                std::cout << "Create database... at "<< this->dbPath << std::endl;
                try {
                    SQLite::Database db(dbPath, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

                    db.exec("CREATE TABLE IF NOT EXISTS users ("
                        "id INTEGER PRIMARY KEY, "
                        "username TEXT, "
                        "password TEXT, "
                        "updated_at DATETIME, "
                        "created_at DATETIME);");
                std::cout << "database created successful ." << std::endl;
            } catch (std::exception& e) {
                std::cerr << "Error Create Db : " << e.what() << std::endl;
            }
        }



    private:
        std::string dbPath;
    };


    
} // namespace Server



#endif /* !DATABASESSQLITE_HPP_ */
