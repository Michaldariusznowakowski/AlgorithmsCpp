import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class BasicApplication extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("BasicFXML.fxml"));
        primaryStage.setTitle("Hello World");
        primaryStage.setMaxHeight(300);
        primaryStage.setMinHeight(200);
        primaryStage.setMaxWidth(400);
        primaryStage.setMinWidth(300);
        Scene scene = new Scene(root, 300, 200);
        scene.getStylesheets().add(getClass().getResource("style.css").toExternalForm());
        primaryStage.setScene(scene);
        primaryStage.show();
        
    }


    public static void main(String[] args) {
        launch(args);
    }
}