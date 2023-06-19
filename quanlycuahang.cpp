#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>

using namespace std;

class Product{
    private:
        long ID_product;
        string Name_product;
        int Price_product;
        int Quantity_product;
        int Purchase_product;
    public:
        //Nhap thong tin cua san pham
        void Init_product(){
            cout << "ID product: ";
            cin >> ID_product;
            cout << "Name product: ";
            cin.ignore();
            getline(cin,Name_product);
            cout << "Price product: ";
            cin >> Price_product;
            cout << "Quantity product: ";
            cin >> Quantity_product;
            cout << "Purchase product: ";
            cin >> Purchase_product;
        }
        //Hien thi thong tin san pham
        void Display_product(){
            cout << ID_product << setw(20) << Name_product << setw(20) << Price_product << setw(20) << Quantity_product << setw(20) << Purchase_product << endl;
        }
        //Ghi vao file
        void Write_file(ofstream &file){
            file << ID_product << setw(20) << Name_product << setw(20) << Price_product << setw(20) << Quantity_product << setw(20) << Purchase_product << endl;
        }
        //doc file
        void Read_file(ifstream &file){
            file >> ID_product;
            file >> Name_product;
            file >> Price_product;
            file >> Quantity_product;
            file >> Purchase_product;
        }
        //Lay gia tri cua san pham
        long Get_ID(){
            return this->ID_product;
        }
        string Get_Name(){
            return this->Name_product;
        }
        int Get_Price(){
            return this->Price_product;
        }
        int Get_Quantity(){
            return this->Quantity_product;
        }
        int Get_Purchase(){
            return this->Purchase_product;
        }
        //Dat lai thong tin san pham
        void Set_ID(long ID){
            this->ID_product=ID;
        }
        void Set_Name(string Name){
            this->Name_product=Name;
        }
        void Set_Price(int price){
            this->Price_product=price;
        }
        void Set_Quantity(int quantity){
            this->Quantity_product=quantity;
        }
        void Set_Purchase(int purchase){
            this->Purchase_product=purchase;
        }
        //Them bot so luong san pham
        void Add_quantity(int quantity){
            Quantity_product+= quantity;
        }
        void Minus_quantity(int quantity){
            Quantity_product-=quantity;
        }
        friend istream& operator >> (istream& is , Product& product){
            product.Init_product();
            return is;
        }
        friend ostream& operator << (ostream& os, Product& product){
            product.Display_product();
            return os;
        }
};

class Store_manager{
    private:
        vector<Product> List_product;
        vector<Product> List_product_sold;
        int size;
        int size_sold;
    public:
        //Doc danh sach san pham
        void Read_list_product(ifstream &file){
            file.seekg(15, ios_base:: beg);
            file >> size;
            cout << "Total product: " << size << endl;
            file.seekg(79,ios_base::cur);
            List_product.resize(size);
            for (int i = 0; i< size; i++){
                Product product;
                List_product[i].Read_file(file);
            }
            Display_List_product();
        }
        //Nhap danh sach san pham
        void Init_List_product(){
            int n;
            cout << "Quantity of goods: ";
            cin >> n;
            size = size + n;
            List_product.resize(size);
            for (int i = (size-n); i<size; i++){
                cout << "Product " << i+1 << endl;
                Product product;
                cin >> product;
                List_product[i] = product;
            }
            Display_List_product();
        } 
        //Hien thi danh sach san pham
        void Display_List_product(){
            cout << "\t\t******Information Product******" << endl;
            cout << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Purchase" << endl;

            for (int i = 0; i< List_product.size();i++){
                cout << List_product[i];
            }
        }
        //Them san phan vao danh sach
        void Add_product(){
            int n;
            cout << "Add quantity of goods: ";
            cin >> n;
            size = size+n;
            List_product.resize(size);
            for (int i = (size-n); i<size; i++){
                cout << "Product " << i+1 << endl;
                Product product;
                cin >> product;
                List_product[i] = product;
            }
        }
        //Xoa san pham khoi danh sach
        void Delete_product(){
            int found = 0;
            long ID;
            cout << "Delete ID product: ";
            cin >> ID;
            for(int i = 0 ; i< List_product.size();i++){
                if(ID == List_product[i].Get_ID()){
                    found++;
                    size--;
                    List_product.erase(List_product.begin() + i); 
                    cout << "Deleted product with ID " << ID << endl;
                }
            }
            List_product.resize(size);
            if (found == 0)
                cout << "No products with ID: " << ID << endl;
        }
        //Them so luong hang
        void Add_quantity_product(){
            long ID;
            int add_quantity;
            cout << "ID product: ";
            cin >> ID;
            cout << "Number add: ";
            cin >> add_quantity;
            for(int i = 0 ; i< List_product.size();i++){
                if(ID == List_product[i].Get_ID()){   
                    List_product[i].Add_quantity(add_quantity);
                    break;
                }
            }
        }
        //Bot so luong hang
        void Minus_quantity_product(){
            long ID;
            int minus_quantity;
            cout << "ID product: ";
            cin >> ID;
            cout << "Number minus: ";
            cin >> minus_quantity;
            for(int i = 0 ; i< List_product.size();i++){
                if(ID == List_product[i].Get_ID()){   
                    List_product[i].Minus_quantity(minus_quantity);
                    break;
                }
            }
        }
        //Thay doi thong tin cua san pham
        //Thay doi ID
        void Change_ID_product(int i){
            int ID_change;
            cout << "New ID product: ";
            cin >> ID_change;
            List_product[i].Set_ID(ID_change);
        }
        //Thay doi ten
        void Change_Name_product(int i){
            string Name;
            cout << "New Name product: ";
            cin >> Name;
            List_product[i].Set_Name(Name);
        }
        //Thay doi gia
        void Change_Price_product(int i){
            int Price_change;
            cout << "New Price product: ";
            cin >> Price_change;
            List_product[i].Set_Price(Price_change);
        }
        void Change_Purchase_product(int i){
            int Purchase_change;
            cout << "New Purchase product: ";
            cin >> Purchase_change;
            List_product[i].Set_Purchase(Purchase_change);
        }
        void Change_information_product(){
            long ID;
            int select;
            cout << "ID product: ";
            cin >> ID;
            for(int i = 0 ; i< List_product.size();i++){
                if(ID == List_product[i].Get_ID()){   
                    do{
                        cout << "\t*********MENU CHANGE**********" << endl;
                        cout << "\t1.Change ID product" << endl;
                        cout << "\t2.Change Name product" << endl;
                        cout << "\t3.Change Price product" << endl;
                        cout << "\t4.Change Purchase product" << endl;
                        cout << "\t5.Exit" << endl;
                        cout << "Your request: ";
                        cin >> select;

                        switch (select){
                            case 1:
                                Change_ID_product(i);
                                break;
                            case 2:
                                Change_Name_product(i);
                                break;
                            case 3:
                                Change_Price_product(i);
                                break;
                            case 4:
                                Change_Purchase_product(i);
                                break;
                            default:
                                break;
                        }
                    }while(select!=5);
                    break;
                }
            }
        }
        //in file danh sach san pham
        void Export_file_list_product(){
            ofstream file;
            file.open("List_product.txt");
            file << "Total product: " << size << endl;
            if(file.is_open()){
                file << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Purchase" << endl;
                for(int i = 0 ; i<List_product.size();i++){
                    List_product[i].Write_file(file);
                }
                file.close();
            } else {
                cout << "Can not open file";
            }
            cout << "Exported file!!" << endl;
        }
        //Doc file danh sach da ban
        void Read_list_product_sold(ifstream &file){
            file.seekg(20, ios_base:: beg);
            file >> size_sold;
            cout << "Total product sold: " << size_sold << endl;
            file.seekg(79,ios_base::cur);
            List_product_sold.resize(size_sold);
            for (int i = 0; i< size_sold; i++){
                Product product;
                List_product_sold[i].Read_file(file);
            }
            Display_List_product_sold();
        }
        //Nhap danh sach san pham da ban
        void Init_List_product_sold(){
            int n;
            cout << "Quantity product sold: ";
            cin >> n;
            size_sold = size_sold + n;
            List_product_sold.resize(size_sold);
            long ID_sold;
            int Quantity_sold;
            for (int i = (size_sold - n); i < size_sold ; i++){
                cout << "Product sold " << i+1 << endl;
                cout << "ID product sold: ";
                cin >> ID_sold;
                cout << "Quantity product sold: ";
                cin >> Quantity_sold;
                for (int j = 0; j < List_product.size(); j++){
                    if(ID_sold == List_product[j].Get_ID()){
                        if(Quantity_sold > List_product[j].Get_Quantity()){
                            cout << List_product[j].Get_Name() << " not enough products to sell !!!" << endl;
                            size_sold--;
                            i--;
                            List_product_sold.resize(size_sold);
                        }else{
                            int x = 0;
                            for (int k = 0;k<List_product_sold.size();k++){
                                if(ID_sold == List_product_sold[k].Get_ID()){
                                    List_product_sold[k].Add_quantity(Quantity_sold);
                                    x++;
                                    size_sold--;
                                    i--;
                                    List_product_sold.resize(size_sold);
                                }
                            }
                            if(x==0){
                                List_product_sold[i].Set_ID(ID_sold);
                                List_product_sold[i].Set_Name(List_product[j].Get_Name());
                                List_product_sold[i].Set_Price(List_product[j].Get_Price());
                                List_product_sold[i].Set_Quantity(Quantity_sold);
                                List_product_sold[i].Set_Purchase(List_product[j].Get_Purchase());
                            }
                            List_product[j].Minus_quantity(Quantity_sold);
                        }
                    }
                }
            }
            cout << "Updated List product" << endl;
            Display_List_product();
            cout << "Updated List product sold" << endl;
            Display_List_product_sold();
        }
        //Hien thi danh sach san pham da ban
        void Display_List_product_sold(){
            cout << "\t\t******Information Product sold******" << endl;
            cout << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Purchase" << endl;

            for (int i = 0; i< List_product_sold.size();i++){
                cout << List_product_sold[i];
            }
        }
        //in file danh sach da ban
        void Export_file_list_product_sold(){
            ofstream file;
            file.open("List_product_sold.txt");
            file << "Total product sold: " << size_sold << endl;
            if(file.is_open()){
                file << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Purchase" << endl;
                for(int i = 0 ; i<List_product_sold.size();i++){
                    List_product_sold[i].Write_file(file);
                }
                file.close();
            } else {
                cout << "Can not open file";
            }
            cout << "Exported file!!" << endl;
        }
        
        //Menu san pham
        void Menu_List_product(){
            int select;
            do{
            cout << "\t*********MENU**********" << endl;
            cout << "\t1.Init product" << endl;
            cout << "\t2.Display product" << endl;
            cout << "\t3.Add quantity product" << endl;
            cout << "\t4.Minus quantity product" << endl;
            cout << "\t5.Change information produce" << endl;
            cout << "\t6.Add product" << endl;
            cout << "\t7.Delete product" << endl;
            cout << "\t8.Export file" << endl;
            cout << "\t9.Exit" << endl;
            cout << "Your request: ";
            cin >> select;
            
            switch (select) {
                case 1:
                    Init_List_product();
                    break;
                case 2:
                    Display_List_product();
                    break;
                case 3:
                    Add_quantity_product();
                    break;
                case 4:
                    Minus_quantity_product();
                    break;
                case 5:
                    Change_information_product();
                    break;
                case 6:
                    Add_product();
                    break;
                case 7:
                    Delete_product();
                    break;
                case 8:
                    Export_file_list_product();
                    break;
                default:
                    break;
                }
            }while(select!=9);
        }
        //menu san pham da ban
        void Menu_List_product_sold(){
            int select;
            do{
                cout << "\t*********MENU**********" << endl;
                cout << "\t1.Init product sold" << endl;
                cout << "\t2.Display product sold" << endl;
                cout << "\t3.Export file" << endl;
                cout << "\t4.Exit" << endl;
                cout << "Your request: ";
                cin >> select;

                switch (select){
                    case 1:
                        Init_List_product_sold();
                        break;
                    case 2:
                        Display_List_product_sold();
                        break;
                    case 3:
                        Export_file_list_product_sold();
                        break;
                    default:
                        break;
                }
            }while(select!=4);
        }
        //Lay thong tin trong private
        Product Get_List_product_sold(int i){
            return this->List_product_sold[i];
        }
        Product Get_List_product(int i){
            return this->List_product[i];
        }
        int Get_size_sold(){
            return this->size_sold;
        }
        int Get_size(){
            return this->size;
        }
};

class Interest : public Store_manager{
    private:
        int Purchase_money;
        int Retail_money;
    public:
        //Tinh tien lai
        void Interset_product(){
            Purchase_money = 0;
            Retail_money = 0;
            for (int i = 0; i<Get_size_sold();i++){
                Retail_money = Retail_money + Get_List_product_sold(i).Get_Price() * Get_List_product_sold(i).Get_Quantity();
                Purchase_money = Purchase_money + Get_List_product_sold(i).Get_Purchase() * Get_List_product_sold(i).Get_Quantity();
            }
        }
        //Hien thi tien lai
        void Display_Interest(){
            cout << "Interest: " << Retail_money - Purchase_money << endl;
        }
        //in file quan ly cua hang
        void Export_file(){
            ofstream file;
            file.open("Store_Manager.txt");
            file << "Total product: " << Get_size() << endl;
            if(file.is_open()){
                file << "\t\t**********List product**********" << endl;
                file << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Purchase" << endl;
                for(int i = 0 ; i<Get_size();i++){
                    Get_List_product(i).Write_file(file);
                }
                file << "\t\t*********List product sold*********" << endl;
                file << "ID" << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Purchase" << endl;
                for(int i = 0 ; i<Get_size_sold();i++){
                    Get_List_product_sold(i).Write_file(file);
                }
                file << "Interest: " << Retail_money - Purchase_money << endl;
                file.close();
            } else {
                cout << "Can not open file";
            }
            cout << "Exported file!!" << endl;
        }
        //in Menu
        void Menu(){
            ifstream filei;
            filei.open("List_product.txt", ios_base :: in);
            Read_list_product(filei);
            filei.close();
            ifstream fileis;
            fileis.open("List_product_sold.txt", ios_base :: in);
            Read_list_product_sold(fileis);
            fileis.close();
            int select_List;
                    
            do {
                cout << "\t*********MENU**********" << endl;
                cout << "\t1.Init List product" << endl;
                cout << "\t2.Init List product sold" << endl;
                cout << "\t3.Export file" << endl;
                cout << "\t4.Exit" << endl;
                cout << "Your request: ";
                cin >> select_List;

                switch (select_List) {
                case 1:
                    Menu_List_product();
                    break;
                case 2:
                    Menu_List_product_sold();
                    break;
                case 3:
                    Export_file();
                    Interset_product();
                    Display_Interest();
                    break;
                default:
                    break;
                }
            }while(select_List!=4);
        }
};

int main(){
    Interest *store = new Interest();

    store->Menu();
    delete store;

    return 0;
}