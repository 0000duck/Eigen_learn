#include <iostream>
#include <ctime>
#include <Eigen/Dense>              // ���ܾ���Ĵ�������
using namespace std;
#define MATRIX_SIZE 100
 
int main()
{
	// Eigen �Ծ���Ϊ�������ݵ�Ԫ������һ��ģ���࣬����ǰ��������Ϊ: �������ͣ��У���
	Eigen::Matrix<float, 2, 3> matrix_23;          // ����һ��2*3��float����
	// ͬʱEigenͨ��typedef �ṩ������������ͣ������ײ�����Eigen::Matrix
	// ����Vector3dʵ������Eigen::Matrix<double,3,1>,����ά����
	Eigen::Vector3d v_3d;
	// ����һ����
	Eigen::Matrix<float, 3, 1> vd_3d;
 
	// Matrix3d ʵ������Eigen::Matrix<double,3,3>
	Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();    // ��ʼ��Ϊ��
 
	// �����ȷ�������С������ʹ�ö�̬��С�ľ���
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
	// ������һ�ָ��򵥵�д��
	Eigen::MatrixXd matrix_x;
 
	// �����Ƕ�Eigen����Ĳ���
	// ��������(��ʼ����
	matrix_23 << 1, 2, 3, 4, 5, 6;            
	// ���
	cout << matrix_23 << endl;           
 
	// ��()���ʾ����е�Ԫ��
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cout << matrix_23(i, j) << "\t";
	cout << endl;
 
	// ��������������(ʵ������Ȼ�Ǿ���;���)
	v_3d << 3, 2, 1;
	vd_3d << 4, 5, 6;
 
	// ������Eigen���㲻�ܻ�����ֲ�ͬ���͵ľ����������Ǵ��,������double��float
	// Eigen::Matrix<double, 2, 1> result_wrong_type = matrix_23 * v_3d;
	// Ӧ����ʽת��
	Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
	cout << result << endl;
 
	// ��׼�ľ���˷�
	Eigen::Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
	cout << result2 << endl;
 
	// �����ά�����ԣ��ᱨ��
	// Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;
 
	// һЩ��������
	// ��������Ͳ���ʾ�ˣ�ֱ����+-*/���ɡ�
	matrix_33 = Eigen::Matrix3d::Random();      // ���������
	cout << matrix_33 << endl;                  // �������
	cout << "-------------------------" << endl;
	cout << matrix_33.transpose() << endl;      // ����ת��
	cout << "-------------------------" << endl;
	cout << matrix_33.sum() << endl;            // ��Ԫ�صĺ�
	cout << "-------------------------" << endl;
	cout << matrix_33.trace() << endl;          // ����ļ�
	cout << "-------------------------" << endl;
	cout << 10 * matrix_33 << endl;             // ����
	cout << "-------------------------" << endl;
	cout << matrix_33.inverse() << endl;        // ��������
	cout << "-------------------------" << endl;
	cout << matrix_33.determinant() << endl;    // ����ʽ
 
	// ����ֵ
	// ʵ�Գƾ�����Ա�֤�Խǻ��ɹ�
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_33.transpose()*matrix_33);
	cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
	cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;   // ����ֵ��Ӧ����������������'

	Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE > matrix_NN;           // ����һ��MATRIX_SIZE*MATRIX_SIZE����
 
	matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);         // �����ʼ��
 
	Eigen::Matrix< double, MATRIX_SIZE, 1> v_Nd;
	v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);
 
	clock_t time_stt = clock();  //����ǰʱ�丳ֵ��time_stt����
	// ֱ������
	Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse()*v_Nd;
	cout << "time use in normal inverse is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
 
	// ͨ���þ���ֽ���������QR�ֽ⣬�ٶȻ��ܶ�
	time_stt = clock();
	x = matrix_NN.colPivHouseholderQr().solve(v_Nd);   // QR�ֽ�
	cout << "time use in Qr decomposition is " << 1000 * (clock() - time_stt) / (double)CLOCKS_PER_SEC << "ms" << endl;
	return 0;
}

 
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  Matrix3d m = Matrix3d::Random();//"Matrix3d"ֱ�Ӷ�����һ��3-by-3�ķ������
  m = (m + Matrix3d::Constant(1.2)) * 50;
  cout << "m =" << endl << m << endl;
  Vector3d v(1,2,3); //"Vector3d"ֱ�Ӷ�����һ��ά��Ϊ3��������
  cout << "m * v =" << endl << m * v << endl;
}


 

�̶��ߴ��붯̬�ߴ�
ʲôʱ��Ӧ��ʹ�ù̶��ߴ磨����Matrix4f����ʲôʱ��Ӧ��ʹ�ö�̬�ߴ磨����MatrixXf����
�򵥵Ĵ��ǣ��ڿ��ܵĵط�ʹ�ù̶��ߴ�����ʾ�ǳ�С�ĳߴ磬����Ҫ�ĵط�ʹ�ö�̬�ߴ�����ʾ�ϴ�ĳߴ硣
����С�ߴ磬�����Ƕ���С�ڣ���Լ��16�ĳߴ磬ʹ�ù̶��ߴ�������м���ĺô�����Ϊ��ʹEigen�����˶�̬�ڴ���䲢չ����ѭ�������ڲ����̶���С�ı�������ֻ��һ���򵥵����飬��Matrix4f mymatrix;��ĵ���ֻ������float[16]; �����ȷʵ����������ʱ��ɱ������֮�£���̬��С���������ʼ�շ����ڶ��ϣ����MatrixXf mymatrix���У��У�;������float * mymatrix = new [��*��];����֮�⣬MatrixXf���󻹽��������������洢Ϊ��Ա��������Ȼ��ʹ�ù̶���С�������ǣ�ֻ�е����ڱ���ʱ֪����Сʱ�����п�����������ͬ���������㹻��ĳߴ磨���磬���ڴ��ڣ���Լ��32�ĳߴ磩��ʹ�ù̶��ߴ���������Ʊ�ÿ��Ժ��Բ��ơ��������ǣ�����ʹ�ú����ڲ��Ĺ̶���С�����ǳ���ľ�����ܻᵼ�¶�ջ�������ΪEigen�᳢���Զ����������Ϊ�ֲ�����������ͨ�����ڶ�ջ����ɵġ�����������������ʹ�ö�̬�ߴ�ʱ��Eigen���ɳ��Խ���ʸ������ʹ��SIMDָ�����μ��ο�ʸ������

MatrixXcf a = MatrixXcf::Random(2, 2); //MatrixXcf Ϊ��������
                cout << "Here is the matrix a\n"
                     << a << endl; //����
                cout << "Here is the matrix a^T\n"
                     << a.transpose() << endl;    //ת��
                cout << "Here is the conjugate of a\n"
                     << a.conjugate() << endl;    //����
                cout << "Here is the matrix a^*\n"
                     << a.adjoint() << endl;       //����



// ע�⣺����һ�����������ת�ã�Ӧ��ʹ��.transposeInPlace()
        {
                Matrix2i a;
                a << 1, 2, 3, 4;
                cout << "Here is the matrix a:\n"
                     << a << endl;
                // �ӡ�������������Ӧ����������������������
                // a = a.transpose(); // !!! do NOT do this !!!
                // cout << "and the result of the aliasing effect:\n"
                //      << a << endl;

                // Ӧ��������������
                a.transposeInPlace();
                cout << "and after being transposed:\n"
                     << a << endl;
        }


mat << 1, 2,3, 4;
        //Ԫ�غͣ�Ԫ�س˻���Ԫ�ؾ�ֵ����Сϵ�������ϵ������
        cout << "Here is mat.sum():       " << mat.sum() << endl;
        cout << "Here is mat.prod():      " << mat.prod() << endl;
        cout << "Here is mat.mean():      " << mat.mean() << endl;
        cout << "Here is mat.minCoeff():  " << mat.minCoeff() << endl;
        cout << "Here is mat.maxCoeff():  " << mat.maxCoeff() << endl;
        cout << "Here is mat.trace():     " << mat.trace() << endl;

// ���Է���Ԫ��λ��
        Matrix3f m = Matrix3f::Random();
        std::ptrdiff_t i, j;
        float minOfM = m.minCoeff(&i, &j);
        cout << "Here is the matrix m:\n"
             << m << endl;
        cout << "Its minimum coefficient (" << minOfM
             << ") is at position (" << i << "," << j << ")\n\n";
        RowVector4i v = RowVector4i::Random();
        int maxOfV = v.maxCoeff(&i);
        cout << "Here is the vector v: " << v << endl;
        cout << "Its maximum coefficient (" << maxOfV
             << ") is at position " << i << endl;


        ArrayXXf m(2, 2); // ��ά��̬float��������

        // assign some values coefficient by coefficient
        m(0, 0) = 1.0;
        m(0, 1) = 2.0;
        m(1, 0) = 3.0;
        m(1, 1) = m(0, 1) + m(1, 0);

        // print values to standard output
        cout << m << endl
             << endl;

        // using the comma-initializer is also allowed
        m << 1.0, 2.0, 3.0, 4.0;

        // print values to standard output
        cout << m << endl;


//�����Խ�һ��������Ա������������Ĺ�����ʽ��ͬ��
        //��������������ͬ�ĵط��ǽ�����������ˡ�
        //���󽫳˷�����Ϊ����˻��������齫�˷�����Ϊ��ϵ���˻���
        //��ˣ����ҽ����������������ͬ��ά��ʱ�����ǲ������
        LOG();
        ArrayXXf a(2, 2);
        ArrayXXf b(2, 2);
        a << 1, 2,
            3, 4;
        b << 5, 6,
            7, 8;
        cout << "a * b = " << endl
             << a * b << endl;
        // Output is:
        // a * b =
        //  5 12
        // 21 32
}

ʲôʱ��Ӧ��ʹ��Matrix��Ķ���ʲôʱ��Ӧ��ʹ��Array��Ķ���
�����ܶ�����Ӧ�þ������㣬Ҳ���ܶԾ���Ӧ���������㡣��ˣ��������Ҫ�������Դ������㣨�������˷�������Ӧʹ�þ��������Ҫ����ϵ�����㣬��Ӧʹ�����顣���ǣ���ʱ��������ô�򵥣���������Ҫͬʱʹ��Matrix��Array����������������£�����Ҫ������ת��Ϊ�������ת��������ѡ�񽫶�������Ϊ���黹�Ǿ��󣬶����Է������в�����������ʽ����.array()���������Խ�����"ת��"Ϊ������ʽ����˿������ɵ�Ӧ�ð�ϵ���������㡣�෴��������ʽ����.matrix()������������Eigen���ʽ����һ������û���κ�����ʱ������ֻҪ���ñ����������Ż���.array������.matrix() �ɱ�������ֵ����Ϊ��ֵ��Eigen��ֹ�ڱ��ʽ�л�Ͼ�������顣���磬������ֱ�Ӿ����������ӡ������+�Ĳ�����Ҫô���Ǿ���Ҫô�������顣���ǣ�ʹ��.array������.matrix�����������ɵؽ���ת��Ϊ��һ�֡�
 //��������ע�⡫��������
�˹���������Ǹ�ֵ�����=������������ʽ����������������������ʽ�������������������ʾ����ʾ���ͨ��ʹ��.array����������Matrix����ʹ��������������磬�����Ҫ��������ͣ���������ת��Ϊ���У��������������ϵ�����ǲ������ָ����������������ǺϷ��ģ���Ϊ�����������������ʽ������ı�������result = m.array() * n.array()mnresult
ʵ���ϣ�����ʹ������ǳ��ձ飬������EigenΪ�����ṩ��const .cwiseProduct()����������ϵ���˻���
        MatrixXf m(2, 2);
        MatrixXf n(2, 2);
        MatrixXf result(2, 2);
        m << 1, 2,
            3, 4;
        n << 5, 6,
            7, 8;
        result = m * n;
        cout << "-- Matrix m*n: --" << endl
             << result << endl
             << endl;
        result = m.array() * n.array();
        cout << "-- Array m*n: --" << endl
             << result << endl
             << endl;
        result = m.cwiseProduct(n);
        cout << "-- With cwiseProduct: --" << endl
             << result << endl
             << endl;
        result = m.array() + 4;
        cout << "-- Array m + 4: --" << endl
             << result << endl
             << endl;
        // Output is:
        // -- Matrix m*n: --
        // 19 22
        // 43 50
        // -- Array m*n: --
        //  5 12
        // 21 32
        // -- With cwiseProduct: --
        //  5 12
        // 21 32
        // -- Array m + 4: --
        // 5 6
        // 7 8

��Ƭ
Eigen::Matrix4f m;
        m << 1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16;
        cout << "m.leftCols(2) =" << endl
             << m.leftCols(2) << endl
             << endl;
        cout << "m.bottomRows<2>() =" << endl
             << m.bottomRows<2>() << endl
             << endl;
        m.topLeftCorner(1, 3) = m.bottomRightCorner(3, 1).transpose();
        cout << "After assignment, m = " << endl
             << m << endl;
        // Output is:
        // m.leftCols(2) =
        //  1  2
        //  5  6
        //  9 10
        // 13 14
        // m.bottomRows<2>() =
        //  9 10 11 12
        // 13 14 15 16
        // After assignment, m =
        //  8 12 16  4
        //  5  6  7  8
        //  9 10 11 12
        // 13 14 15 16

Eigen::ArrayXf v(6);
        v << 1, 2, 3, 4, 5, 6;
        cout << "v.head(3) =" << endl
             << v.head(3) << endl
             << endl;
        cout << "v.tail<3>() = " << endl
             << v.tail<3>() << endl
             << endl;
        v.segment(1, 4) *= 2;
        cout << "after 'v.segment(1,4) *= 2', v =" << endl
             << v << endl;

        // Output is:
        // v.head(3) =
        // 1
        // 2
        // 3

        // v.tail<3>() =
        // 4
        // 5
        // 6

        // after 'v.segment(1,4) *= 2', v =
        //  1
        //  4
        //  6
        //  8
        // 10
        //  6

//���⣬��ʼ���б��Ԫ�ر�����������������ͨ������;�ǽ����������������һ�����磬���ǽ�����������������һ��ķ�����ע�⣺�������������ס�����������ô�С��Ȼ�����ʹ�ö��ų�ʼ������
        RowVectorXd vec1(3);
        vec1 << 1, 2, 3;
        RowVectorXd vec2(4);
        vec2 << 1, 4, 9, 16;
        RowVectorXd joined(7);
        joined << vec1, vec2;

        //  �Ծ����ĳһ�鸳ֵ
        Matrix3f m;
        m.row(0) << 1, 2, 3;
        m.block(1, 0, 2, 2) << 4, 5, 7, 8;
        m.col(2).tail(2) << 6, 9;

        �������ı�ʾ����
// ģ����Matrix<>��Array<>�о�̬���������԰�����ʼ����
        //�����ֱ���:
        //��һ�����岻��������ֻ�����ڹ̶���С�Ķ������Ҫ����̬�ߴ�����ʼ��Ϊ�㣬����Ҫָ���ߴ硣
        //�ڶ���������Ҫһ�����������ҿ�������һά��̬�ߴ����
        //������������Ҫ�������������ҿ������ڶ�ά����

        std::cout << "A fixed-size array:\n";
        Array33f a1 = Array33f::Zero();   //����float3*3�ľ��󣬲��ҽ�ֵȫ����Ϊ0
        std::cout << "A one-dimensional dynamic-size array:\n";
        ArrayXf a2 = ArrayXf::Zero(3);    //������̬���������ҽ�ֵ��Ϊ0
        std::cout << "A two-dimensional dynamic-size array:\n";
        ArrayXXf a3 = ArrayXXf::Zero(3, 4); //������̬���󣬲��ҽ�ֵ��Ϊ0

        //ͬ������̬����Constant(value)�Ὣ����ϵ������Ϊvalue��
        // �����Ҫָ������Ĵ�С���򸽼Ӳ�������value����֮ǰ����
        // MatrixXd::Constant(rows, cols, value)��
        //Identity()��õ�λ����, �˷�����������Matrix����������Array����Ϊ"��λ����"�����Դ������
        //�÷���LinSpaced���ߴ磬�ͣ��ߣ��ǽ������������һά����; ������һ��ָ����С����������ϵ����low��֮��ƽ�����high��
        //����LinSpaced()����ʾ��˵���˸�ʾ������ʾ����ӡһ�ű�����а����Զ�Ϊ��λ�ĽǶȣ��Ի���Ϊ��λ����Ӧ�Ƕ��Լ����ǵ����Һ�����ֵ��
        ArrayXXf table(10, 4);  //��ʼ��Ϊ
        table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
        table.col(1) = M_PI / 180 * table.col(0);
        table.col(2) = table.col(1).sin();
        table.col(3) = table.col(1).cos();

        //Eigen����������setZero()��MatrixBase :: setIdentity������DenseBase :: setLinSpaced()֮���ʵ�ó������������ִ�д˲�����
        //�������Բ��ö���ĳ�Ա�������ó�ʼֵ��
        //�����ʾ���Ա������ֹ�������J =[O  I ; I O ] ����
        // ʹ�þ�̬������operator=
        const int size = 6;
        MatrixXd mat1(size, size);
        mat1.topLeftCorner(size / 2, size / 2) = MatrixXd::Zero(size / 2, size / 2);
        mat1.topRightCorner(size / 2, size / 2) = MatrixXd::Identity(size / 2, size / 2);
        mat1.bottomLeftCorner(size / 2, size / 2) = MatrixXd::Identity(size / 2, size / 2);
        mat1.bottomRightCorner(size / 2, size / 2) = MatrixXd::Zero(size / 2, size / 2);

        //ʹ��.setXxx()����
        MatrixXd mat2(size, size);
        mat2.topLeftCorner(size / 2, size / 2).setZero();
        mat2.topRightCorner(size / 2, size / 2).setIdentity();
        mat2.bottomLeftCorner(size / 2, size / 2).setIdentity();
        mat2.bottomRightCorner(size / 2, size / 2).setZero();

        MatrixXd mat3(size, size);
        //ʹ�þ�̬�����Ͷ��ų�ʼ��
        mat3 << MatrixXd::Zero(size / 2, size / 2), MatrixXd::Identity(size / 2, size / 2),
            MatrixXd::Identity(size / 2, size / 2), MatrixXd::Zero(size / 2, size / 2);

void UsageAsTemporaryObjects()  //ʹ�þ�̬����
{
        //������ʾ������������ʱ���ڸ�ֵ��������Ҳ�ʹ�þ�̬����Zero()��Constant()����ʼ�������������Խ���Щ������Ϊ���ؾ�������顣ʵ���ϣ����Ƿ�����ν��**���ʽ����**����Щ���ʽ��������Ҫʱ��ֵ����������飬��˸��﷨��������κο�������Щ���ʽҲ����������ʱ����
        MatrixXd m = MatrixXd::Random(3, 3);
        m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;  //ʹ��constant��ʼ������
        v << 1, 2, 3;

        // The comma-initializer, too, can also be used to construct temporary objects. The following example constructs a random matrix of size 2-by-3,and then multiplies this matrix on the left with [0 1; 1 0] ���ų�ʼ������Ҳ�������ڹ�����ʱ���� �����ʾ������һ����СΪ2��3���������Ȼ�󽫸���ߵľ������[0 1; 1 0]
        MatrixXf mat = MatrixXf::Random(2, 3);   //�������2*3�ĸ���������
        // �������ʱ�Ӿ���Ķ��ų�ʼ��֮�󣬱���ʹ��finish������������ȡʵ�ʵľ������finished ������endl��������������
        mat = (MatrixXf(2, 2) << 0, 1, 1, 0).finished() * mat;
        std::cout << mat << std::endl;
}
void NormComputations()
{
        // ��Щ����Ҳ�����ھ��������㡣����������£�n��p������Ϊ��С��n * p����������
        // ��ˣ�����norm()��������" Frobenius"��" Hilbert-Schmidt"������
        // �����Ҫ������ϵ�������l^p��������ʹ��lpNorm <p>()��
        // �����Ҫ���������ģ�����p���Բ�������ֵInfinity������ϵ������ֵ�����ֵ��
        VectorXf v(2);
        MatrixXf m(2, 2), n(2, 2);
        v << -1,
            2;

        m << 1, -2,
            -3, 4;
        // ��������
        cout << "v.squaredNorm() = " << v.squaredNorm() << endl;            //2����
        cout << "v.norm() = " << v.norm() << endl;                           //����.squaredNorm()��ƽ����
        cout << "v.lpNorm<1>() = " << v.lpNorm<1>() << endl;                //һ�׷���
        cout << "v.lpNorm<Infinity>() = " << v.lpNorm<Infinity>() << endl;       //�����
        cout << endl;
        // ������
        cout << "m.squaredNorm() = " << m.squaredNorm() << endl;
        cout << "m.norm() = " << m.norm() << endl;
        cout << "m.lpNorm<1>() = " << m.lpNorm<1>() << endl;
        cout << "m.lpNorm<Infinity>() = " << m.lpNorm<Infinity>() << endl;

        // Ҳ���Լ�����1�����������
        MatrixXf mat(2, 2);
        mat << 1, -2,
            -3, 4;
        cout << "1-norm(mat)     = " << mat.cwiseAbs().colwise().sum().maxCoeff()
             << " == " << mat.colwise().lpNorm<1>().maxCoeff() << endl;
        cout << "infty-norm(mat) = " << mat.cwiseAbs().rowwise().sum().maxCoeff()
             << " == " << mat.rowwise().lpNorm<1>().maxCoeff() << endl;
}

���ݹ�Լ��ָ�ھ����ܱ�������ԭò��ǰ���£�����޶ȵؾ�������������ɸ�����ı�Ҫǰ��������ھ��������Ϥ���ݱ������ݣ�Mat.colwise()���Ϊ�ֱ�ȥ�������ÿһ�У�Ȼ��������maxCoeff()����������ÿһ�е����ֵ����Ҫע����ǣ�colwise���ص���һ�����������з���ά����rowwise���ص���һ�����������з���ά����

Aliasing
    �������������ڸ�ֵ�����Ҷ���ͬһ������ʱ����mat = mat.transpose();�������֮һ��ʹ��eval()����������������ʵ��
  
    �����xxxInplace()����������������ɴﵽ���Ч��Ч������transposeInPlace()
 
    ͨ������£����Ԫ�صı��ֻ���Ԫ���Լ��йأ���ôһ�㲻���������������䣺mat = (2 * mat - MatrixXf::Identity(2, 2)).array().square();

void Visitors()
{
        // �����ھ�������������Ԫ����
        //��Ҫ���һ��ϵ����Matrix��Array�е�λ��ʱ�������ߺ����á�
        //��򵥵�ʾ����maxCoeff����x����y����minCoeff����x����y���������ڲ���Matrix��Array��������Сϵ����λ�á�
        //���ݸ������ߵĲ�����ָ��Ҫ�洢�к���λ�õı�����ָ�롣��Щ����ӦΪIndex���ͣ�

        Eigen::MatrixXf m(2, 2);

        m << 1, 2,
            3, 4;
        //�õ����ֵ��λ��
        MatrixXf::Index maxRow, maxCol;
        float max = m.maxCoeff(&maxRow, &maxCol);
        //�õ���Сֵ��λ��
        MatrixXf::Index minRow, minCol;
        float min = m.minCoeff(&minRow, &minCol);
}

void PartialReductions() ��������
{
        // ��ס,element-wise�ǰ�Ԫ�صģ���ôcolwise()��rowwise()��ʾ���л��е�
        //���ֹ�Լ�ǿ�����Matrix��Array�ϰ��л��в����Ĺ�Լ����ÿ���л���Ӧ�ù�Լ���㲢���ؾ�����Ӧֵ���л���������
        //һ���򵥵�ʾ���ǻ�ȡ����������ÿһ����Ԫ�ص����ֵ����������洢���������У�
        // column-wise������������row-wise������������ɶ��˼��Ӧ����Ƶײ�������Ժ��ٿ�   
        Eigen::MatrixXf mat(2, 4);
        mat << 1, 2, 6, 9,
            3, 1, 7, 2;
        std::cout << "Column's maximum: " << std::endl
                  << mat.colwise().maxCoeff() << std::endl; // ���ھ���mat��ÿһ�У�ȡ���ϵ��ֵ
        // Ҳ���Զ��в���
        std::cout << "Row's maximum: " << std::endl
                  << mat.rowwise().maxCoeff() << std::endl; // ���ھ���mat��ÿһ�У�ȡ���ϵ��ֵ
}
void CombiningPartialReductionsWithOtherOperations()
{
        MatrixXf mat(2, 4);
        mat << 1, 2, 6, 9,
            3, 1, 7, 2;

        MatrixXf::Index maxIndex;
        float maxNorm = mat.colwise().sum().maxCoeff(&maxIndex); //  ���ھ����ÿһ���е�Ԫ����ͣ���������ϵ���ڵ�2��
        std::cout << "Maximum sum at position " << maxIndex << std::endl;
        std::cout << "The corresponding vector is: " << std::endl;
        std::cout << mat.col(maxIndex) << std::endl;
        std::cout << "And its sum is is: " << maxNorm << std::endl;
}

void Broadcasting()�㲥����
{
        LOG();
        //�㲥����ĸ��������ڲ��ֹ�Լ���������ڹ㲥������һ�����ʽ�������������л��У�ͨ����һ�������ϸ��ƶ�������Ϊ����
        //һ���򵥵�ʾ���ǽ�ĳ����������ӵ������е�ÿһ�С������ͨ�����·�ʽ��ɣ�
        Eigen::MatrixXf mat(2, 4);
        Eigen::VectorXf v(2);
        mat << 1, 2, 6, 9,
            3, 1, 7, 2;
        v << 0,            //������
            1;

        //add v to each column of m
        //mat.colwise() += v�����ֵ�Ч�ķ�ʽ����ָ�
        //�����������v�������ÿһ�С����ߣ����Խ������Ϊ�ظ�����v�Ĵ����γ��ĳ˶�����Ȼ����ӵ�mat
        mat.colwise() += v;
        std::cout << "Broadcasting result: " << std::endl;
        std::cout << mat << std::endl;
        // Output is:
        // Broadcasting result:
        // 1 2 6 9
        // 4 2 8 3

        // �ھ����ϣ����ǿ���ִ��-=,+=,+,-���������ǲ��ܽ���*=,/=,*,/����
        // �����������ǿ�ִ��*=,/=,*,/����
        // If you want multiply column 0 of a matrix mat with v(0), column 1 with v(1), and so on, then use mat = mat * v.asDiagonal().Ҫ���л�������ӵ���������ΪVector���ͣ����Ҳ���ΪMatrix����������㣬�����ֱ���ʱ���󡣹㲥����ֻ��Ӧ����Vector���͵Ķ�����ͬ��������������VectorXf��ArrayXf��

        // ͬ����Ҳ���Զ���ִ�д˲���
        {
                Eigen::MatrixXf mat(2, 4);
                Eigen::VectorXf v(4);  
                mat << 1, 2, 6, 9,
                    3, 1, 7, 2;
                v << 0, 1, 2, 3;          //������
                //add v to each row of m
                mat.rowwise() += v.transpose();
                std::cout << "Broadcasting result: " << std::endl;
                std::cout << mat << std::endl;

                //  Broadcasting result:
                //  1  3  8 12
                //  3  2  9  5
        }
}

void CombiningBroadcastingWithOtherOperations()      //�ѹ㲥�������������������һ��
{
        // �㲥�����������������������������в���������Լ�Ͳ��ֹ�Լ���ϡ�
        //�����Ѿ������˹㲥��Լ��Ͳ���Լ�����ǿ��������о�һ�����߼���ʾ������ʾ��v�ھ���������ҵ������������m��ŷ����¾��뽫�ڱ�ʾ����ʹ�ã�������в��ֹ�Լ��ΪsquaredNorm()��ƽ��ŷ����¾��룺
        Eigen::MatrixXf m(2, 4);
        Eigen::VectorXf v(2);
        m << 1, 23, 6, 9,
            3, 11, 7, 2;
        v << 2,
            3;
        MatrixXf::Index index;
        // find nearest neighbour
        (m.colwise() - v).colwise().squaredNorm().minCoeff(&index);
        cout << "Nearest neighbour is column " << index << ":" << endl;
        cout << m.col(index) << endl;
}

MAP��ʹ��
//��ʱ������Ҫ��Eigen��ʹ��Ԥ�������������(C++)��Ϊʸ�������(Eigen)��
//һ��ѡ���Ǹ������ݣ�������������������ϣ�������ڴ档���˵��ǣ�ʹ��Map��ǳ����ס�
// Map �� ʵ��C++�е������ڴ��Eigen����Ľ���
// Map< Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>  >  ��ע�⣬������Ĭ������£�Map����Ҫһ��ģ������� Ҫ����Map������������Ҫ����������Ϣ��ָ����ϵ��������ڴ������ָ�룬�Լ�����ľ����ʸ����״��(ע������ģ������ͺ����β�)
// ���磬Ҫ����һ��float�ڱ���ʱȷ����С�ľ���������ִ�����²�����Map <MatrixXf> mf��pf��rows��columns��;
// ����pf��һ��float *ָ��Ĵ洢�����С��̶���С������ֻ���������ܻ�����Ϊ
// Map <const Vector4i> mi��pi��;
// ����pi��int *������������£����ؽ���С���ݸ����캯������Ϊ���Ѿ���Matrix / Array����ָ����
// ��ע�⣬Mapû��Ĭ�ϵĹ��캯���������봫��һ��ָ������ʼ�����󡣵��ǣ������Խ����Ҫ������ĸ���Map���飩��
// Map�㹻���������ɸ��ֲ�ͬ�����ݱ�ʾ��ʽ������������������ѡ��ģ�������
// Map<typename MatrixType, int MapOptions(MapOptionsָ��ָ����Aligned����Unaligned��Ĭ��ֵΪUnaligned),  typename StrideType>
//StrideType������ʹ��Stride��Ϊ�ڴ�����ָ���Զ��岼�֡�һ��ʾ����ָ�����������������ȸ�ʽ������֯MapConstruct()

void MapConstruct()
{
        int array[8];
        for (int i = 0; i < 8; ++i)
                array[i] = i;
        cout << "Column-major:\n"
             << Map<Matrix<int, 2, 4>>(array) << endl;    //����Ϊ��
        cout << "Row-major:\n"
             << Map<Matrix<int, 2, 4, RowMajor>>(array) << endl; //����Ϊ��
        cout << "Row-major using stride:\n"//
             << Map<Matrix<int, 2, 4>, Unaligned, Stride<1, 4>>(array) << endl;
        //Output is:
        //Column-major:
        // 0 2 4 6
        // 1 3 5 7
        // Row-major:
        // 0 1 2 3
        // 4 5 6 7
        // Row-major using stride:
        // 0 1 2 3
        // 4 5 6 7

        //���ǣ�Stride������� �й���ϸ��Ϣ����μ�Map��Stride����ĵ���
}

void UsingMapVariables()
{

        typedef Matrix<float, 1, Dynamic> MatrixType;
        typedef Map<MatrixType> MapType;
        typedef Map<const MatrixType> MapTypeConst;              // a read-only map
        const int n_dims = 5;

        MatrixType m1(n_dims), m2(n_dims);
        m1.setRandom();                        //m1��Ϊ���-1��1 
        m2.setRandom();
        float *p = &m2(0);                        // ��ȡ�洢m2���ݵĵ�ַ
        MapType m2map(p, m2.size());            // m2map��m2��������
        MapTypeConst m2mapconst(p, m2.size());  // һ��m2��ֻ��������
        cout << "m1: " << m1 << endl;
        cout << "m2: " << m2 << endl;
        cout << "Squared euclidean distance: " << (m1 - m2).squaredNorm() << endl;
        cout << "Squared euclidean distance, using map: " << (m1 - m2map).squaredNorm() << endl;
        m2map(3) = 7;                       // this will change m2, since they share the same array
        cout << "Updated m2: " << m2 << endl;
        cout << "m2 coefficient 2, constant accessor: " << m2mapconst(2) << endl;
        //Output is:
        // m1:   0.68 -0.211  0.566  0.597  0.823
        // m2: -0.605  -0.33  0.536 -0.444  0.108
        // Squared euclidean distance: 3.26
        // Squared euclidean distance, using map: 3.26
        // Updated m2: -0.605  -0.33  0.536      7  0.108
        // m2 coefficient 2, constant accessor: 0.536
}

void ChangingTheMappedArray()  //�ı��Ѿ�map������
{
        //����ʹ��C ++" placement new"(λ��new���ڳ���Ա�������ڴ����Ԫ��) �﷨������������Map��������顣�����г��֣�������������ڴ����������Ϊ�﷨ָ���˴洢�����λ�á��򵥵�˵��λ��newֻ����ָ��λ��д�����ݣ���������newһ�������ڶ��Ϸ����ڴ棬Ȼ�������γ�ʼ��������Ҳ��Ϊʲô��λ��new����Ϊ���ᰴ������ָ����λ�ù������
        int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Map<RowVectorXi> v(data, 4);                     //ֻ��ǰ�ĸ��Ž�map
        cout << "The mapped vector v is: " << v << "\n";     
        new (&v) Map<RowVectorXi>(data + 4, 5);           //��ָ��λ��д������
        cout << "Now v is: " << v << "\n";
        //The mapped vector v is: 1 2 3 4
        //Now v is: 5 6 7 8 9
        // TODO : �̳���û��ָ��n_matrices
        // VectorXf b(n_matrices);
        // for (int i = 0; i < n_matrices; i++)
        // {
        //         new (&A) Map<Matrix3f>(get_matrix_pointer(i));
        //         b(i) = A.trace();}
}
}
void Reshape() //����
{
        //Reshape���������޸ľ���Ĵ�С��ͬʱ������ͬ��ϵ���������޸��������������ڱ���ʱ��С�����ǲ����ܵģ�֮�⣬�÷���������ʹ��Map���ڴ洢�ϴ�����ͬ����ͼ�����Ǵ��������һά������ͼ�ĵ���ʾ����
        MatrixXf M1(3, 3);                   // Column-major storage
        // ע�⣺���ų�ʼ����Ϊ�˷�������������󣬵��ǵײ�洢�ǰ���������˳��洢��
        M1 << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;
        Map<RowVectorXf> v1(M1.data(), M1.size());
        cout << "v1:" << endl
             << v1 << endl;
        Matrix<float, Dynamic, Dynamic, RowMajor> M2(M1);//�˴�Ĭ����ColMajor
        Map<RowVectorXf> v2(M2.data(), M2.size());
        cout << "v2:" << endl
             << v2 << endl;
        //Output is:
        // v1:
        // 1 4 7 2 5 8 3 6 9
        // v2:
        // 1 2 3 4 5 6 7 8 9
        //ע���������Ĵ洢˳������޸�������ͼ��ϵ����˳��������һ����2x6��������Ϊ6x2�����ʾ����
        {
                MatrixXf M1(2, 6); // Column-major storage
                M1 << 1, 2, 3, 4, 5, 6,
                    7, 8, 9, 10, 11, 12;
                Map<MatrixXf> M2(M1.data(), 6, 2);
                cout << "M2:" << endl
                     << M2 << endl;
                //Output is:
                //  M2:
                //  1  4
                //  7 10
                //  2  5
                //  8 11
                //  3  6
                //  9 12
        }
}

void Slicing()  //��Ƭ
{
        //��Ƭ������ȡһ���ھ����ھ��ȼ�����У��л�Ԫ�ء��ٴΣ�Map���������ģ�´˹��ܡ�
        //���磬�������������е�ÿ��PԪ�أ�
        RowVectorXf v = RowVectorXf::LinSpaced(20, 0, 19);
        cout << "Input:" << endl
             << v << endl;
        Map<RowVectorXf, 0, InnerStride<2>> v2(v.data(), v.size() / 2); 
//�˴���InnerStride<2>ָ�����ڲ�������2
        cout << "Even:" << v2 << endl;
        
//Output is:
        //  Input:S
        //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
        // Even: 0  2  4  6  8 10 12 14 16 18

        // TODO:��������е㸴�ӣ����һ�����
        MatrixXf M1 = MatrixXf::Random(3, 8);
        cout << "Column major input:" << endl
             << M1 << "\n";
        Map<MatrixXf, 0, OuterStride<>> M2(M1.data(), M1.rows(), (M1.cols() + 2) / 3, OuterStride<>(M1.outerStride() * 3));    //ѡ���н��в�����
        cout << "1 column over 3:" << endl
             << M2 << "\n";
        typedef Matrix<float, Dynamic, Dynamic, RowMajor> RowMajorMatrixXf;
        RowMajorMatrixXf M3(M1);
        cout << "Row major input:" << endl
             << M3 << "\n";
        Map<RowMajorMatrixXf, 0, Stride<Dynamic, 3>> M4(M3.data(), M3.rows(), (M3.cols() + 2) / 3,
                                                        Stride<Dynamic, 3>(M3.outerStride(), 3));
        cout << "1 column over 3:" << endl
             << M4 << "\n";
        //Column major input:
        //    0.68   0.597   -0.33   0.108   -0.27   0.832  -0.717  -0.514
        //  -0.211   0.823   0.536 -0.0452  0.0268   0.271   0.214  -0.726
        //   0.566  -0.605  -0.444   0.258   0.904   0.435  -0.967   0.608
        // 1 column over 3:
        //    0.68   0.108  -0.717
        //  -0.211 -0.0452   0.214
        //   0.566   0.258  -0.967
        // Row major input:
        //    0.68   0.597   -0.33   0.108   -0.27   0.832  -0.717  -0.514
        //  -0.211   0.823   0.536 -0.0452  0.0268   0.271   0.214  -0.726
        //   0.566  -0.605  -0.444   0.258   0.904   0.435  -0.967   0.608
        // 1 column over 3:
        //    0.68   0.108  -0.717
        //  -0.211 -0.0452   0.214
        //   0.566   0.258  -0.967
}



����
// ��һ�ڱȽ���
// ��Eigen�У�����(aliasing)��ָ��ͬ�ľ��󣨻�����������������ڸ�ֵ������������Ҳ�ĸ�ֵ���; ���磬A = AB ,  a = a^Tb  A=A*A������������ԭ����Eigen���ö�����ֵ�������������к��ģ�Ҳ�������޺��ġ��к��Ļ��������¿��ܲ���ȷ�Ľ�����޺��Ļ������Բ�����ȷ�Ľ����

// �к�����
// ʹ��.eval()���������Խ���������⡣�����˵��.eval()����������ʱ����Ȼ����ִ�и�ֵ���������Eigen�мٶ��ò����ǻ����ģ���ô�����Զ�ʹ��.eval()������������Ҫ������ʾ���á��޺����������ǲ���Ҫ����������ϵ�������޺�������������˷��;��������ӷ���

// �������������ʱ��Eigen��ٶ��������(ע�⣬Eigen3.3�Ժ�İ汾����Ҫ����Ŀ������С�Ƿ�ı���)
//�����֪��û�л����������ʹ��noalias()��

// ��������������£�Eigen�ٶ������ڻ�����⣬������ʵ���Ϸ������������������Ľ����
// Ϊ��ֹ���������������ʹ��eval������xxxInPlace��������֮һ��

void Aliasing()
{
        // ����mat = 2 * mat(��������޺�);��mat = mat.transpose();(�к��Ļ���)��

        MatrixXi mat(3, 3);
        mat << 1, 2, 3, 4, 5, 6, 7, 8, 9;
        cout << "Here is the matrix mat:\n"
             << mat << endl;
        // This assignment shows the aliasing problem
        mat.bottomRightCorner(2, 2) = mat.topLeftCorner(2, 2);
        cout << "After the assignment, mat = \n"
             << mat << endl;

        // Output  is:
        // Here is the matrix mat:
        // 1 2 3
        // 4 5 6
        // 7 8 9
        // After the assignment, mat =
        // 1 2 3
        // 4 1 2
        // 7 4 1

        // mat.bottomRightCorner��2,2��= mat.topLeftCorner��2,2��;
        // �ø�ֵ���л���aliasing����ϵ��mat(1,1)�ȳ�����mat.bottomRightCorner(2,2)�������Ŀ���mat.topLeftCorner(2,2)���ֳ������Ҳ�Ŀ��С�
        // ��������½ǵģ�2,2����Ӧ����mat(1,1)����ǰ��ֵ5�����ǣ������ʾmat(2,2)ʵ����Ϊ1��
        // ��������Eigenʹ���˶�����ֵ�����������
        // mat��1,1��= mat��0,0��;
        // mat��1,2��= mat��0,1��;
        // mat��2,1��= mat��1,0��;
        // mat��2,2��= mat��1,1��;
        // ��ˣ�mat(2,2)��������ֵmat(1,1)�����Ǿ�ֵ��
        // ����ͨ������eval()���������(ע:eval()����������ʱ������������)
        // ������С����ʱ������Ҳ�ᷢ����
        // ���磬���ʽvec = vec.head(n)��mat = mat.block(i,j,r,c)���л�����
        //ͨ�����ڱ���ʱ�޷���⵽���������mat�ڵ�һ��ʾ�����Դ�һ�㣬��齫�����ص���Ҳ������ֻ������⡣
        //����Eigenȷʵ��������ʱ��⵽һЩ����ʵ����Matrix�������������ᵽ��������ʾ������ʾ����

        // Matrix2i a;
        // a << 1, 2, 3, 4;
        // cout << "Here is the matrix a:\n"
        //      << a << endl;
        // a = a.transpose(); // !!! do NOT do this !!!
        // cout << "and the result of the aliasing effect:\n"
        //      << a << endl;

        // �����ʾ����(alising)���⡣
        // ���ǣ�Ĭ������£�Eigenʹ������ʱ��������⵽��������˳�������ʾ������Ϣ
        // void Eigen::DenseBase<Derived>::checkTransposeAliasing(const OtherDerived&) const
        // [with OtherDerived = Eigen::Transpose<Eigen::Matrix<int, 2, 2, 0, 2, 2> >, Derived = Eigen::Matrix<int, 2, 2, 0, 2, 2>]:
        // Assertion `(!internal::check_transpose_aliasing_selector<Scalar,internal::blas_traits<Derived>::IsTransposed,OtherDerived>::run(internal::extract_data(derived()), other))
        // && "aliasing detected during transposition, use transposeInPlace() or evaluate the rhs into a temporary using .eval()"' failed.

        //�û�����ͨ������EIGEN_NO_DEBUG�����ر�Eigen������ʱ����
}

void ResolvingAliasingIssues()  //�����������İ취=.eval()
{
        //���������Eigen���뽫�Ҳ���ȫ����һ����ʱ����/���飬Ȼ����������ࡣ
        //����**eval()**������������,����Ϊ����һ����ʱ����
        MatrixXi mat(3, 3);
        mat << 1, 2, 3, 4, 5, 6, 7, 8, 9;
        cout << "Here is the matrix mat:\n"
             << mat << endl;
        // The eval() solves the aliasing problem
        mat.bottomRightCorner(2, 2) = mat.topLeftCorner(2, 2).eval();
        cout << "After the assignment, mat = \n"
             << mat << endl;

        //��ͬ�Ľ������Ҳ�����ڵڶ�ʾ���У���ת�ã�ֻ�������a = a.transpose();��a = a.transpose().eval();�����ǣ������ֳ�������£��и��õĽ��������
        //Eigen�ṩ��ר�ú���transposeInPlace()���ú���ͨ����ת�����滻����������ʾ��
        MatrixXf a(2, 3);
        a << 1, 2, 3, 4, 5, 6;
        a.transposeInPlace();
             
        //���xxxInPlace()�������ã������ʹ��������Ϊ�����Ը������ָʾ��������ʲô��
        //��Ҳ������Eigen�������ؽ����Ż�����Щ���ṩ��һЩxxxInPlace()������
        // Original function	                      In-place function
        // MatrixBase::adjoint()	          MatrixBase::adjointInPlace()
        // DenseBase::reverse()	                 DenseBase::reverseInPlace()
        // LDLT::solve()	                            LDLT::solveInPlace()
        // LLT::solve()	                                      LLT::solveInPlace()
        // TriangularView::solve()	        TriangularView::solveInPlace()
        // DenseBase::transpose()	       DenseBase::transposeInPlace()

        //����������£����������ʹ�����Ƶı��ʽ��Сvec = vec.head(n)�������ʹ��conservativeResize()��
}

void AliasingAndComponentWiseOperations()
{
        //���ͬһ���������ͬʱ�����ڸ�ֵ������������Ҳ࣬����ܺ�Σ�գ����ͨ���б�Ҫ��ʾ�������Ҳ�. ���ǣ�Ӧ�û���Ԫ�صĲ������������ӷ��������˷�������˷����ǰ�ȫ�ġ�����ʾ�������л�������Ĳ�������ˣ���ʹ��ͬ�ľ�������ڸ�ֵ���ŵ����࣬Ҳ����Ҫeval()��
        MatrixXf mat(2, 2);
        mat << 1, 2, 4, 7;
        cout << "Here is the matrix mat:\n"
             << mat << endl
             << endl;
        mat = 2 * mat;
        cout << "After 'mat = 2 * mat', mat = \n"
             << mat << endl
             << endl;
        mat = mat - MatrixXf::Identity(2, 2);
        cout << "After the subtraction, it becomes\n"
             << mat << endl
             << endl;
        ArrayXXf arr = mat;
        arr = arr.square();
        cout << "After squaring, it becomes\n"
             << arr << endl
             << endl;
        // Combining all operations in one statement:
        mat << 1, 2, 4, 7;
        mat = (2 * mat - MatrixXf::Identity(2, 2)).array().square();
        cout << "Doing everything at once yields\n"
             << mat << endl
             << endl;
        // Output is:
        // Here is the matrix mat:
        // 1 2
        // 4 7

        // After 'mat = 2 * mat', mat =
        //  2  4
        //  8 14

        // After the subtraction, it becomes
        //  1  4
        //  8 13

        // After squaring, it becomes
        //   1  16
        //  64 169

        // Doing everything at once yields
        //   1  16
        //  64 169
        //ͨ����������ʽ�Ҳ�ģ�i��j����Ŀ��ȡ���������������ģ�i��j����Ŀ
        //���������������κα��ʽ����ֵ�ǰ�ȫ�ġ�����������£�������ʾ�������Ҳ�(.evl())��
}

void AliasingAndMatrixMultiplication()
{
        //��Ŀ�����**δ������С**������£�����˷���Eigen��Ψһ�ٶ�Ĭ�������Ϊ�����ġ����ٶ����������ʹ��eval()������ʱ����,�����ǰ�ȫ�ġ���ˣ����matA��ƽ������������matA = matA * matA�ǰ�ȫ�ġ�Eigen�е����������������ٶ�û�л������⣬������Ϊ�����������˲�ͬ�ľ��󣬻�����Ϊ�������Ԫ�صĲ�����
        {
                MatrixXf matA(2, 2);
                matA << 2, 0, 0, 2;
                matA = matA * matA;
                cout << matA << endl;
        }

        // ���ǣ������д��۵ġ�ִ�б��ʽʱmatA = matA * matA, Eigen���ڼ�������ʱ������������ֵ��matA�ĳ˻�����Ȼ���ԣ������ڽ��˻������������������matB = matA * matA��ʱ��Eigen��ִ����ͬ�Ĳ���������������£�ֱ������matB,�������Ƚ�matA*matA������ʱ����Ȼ��������ʱ���������ʱ����ֵ������matB����Ч. ���ǿ���ʹ��noalias����ָʾû�л�����������ʾ��matB.noalias() = matA * matA����ʹEigen����matA * matAֱ�ӽ�����˻���matB��������
        {
                MatrixXf matA(2, 2), matB(2, 2);
                matA << 2, 0, 0, 2;
                // �򵥵���Ч�ʵ�
                matB = matA * matA;
                cout << matB << endl;
                // ���ӵ���Ч�ʸ�
                matB.noalias() = matA * matA;
                cout << matB << endl;
        }

        {
                //���⣬��Eigen 3.3 ��ʼ��
                //���������Ŀ�����Ĵ�С(ע�⣬�����еĲ����ٶ�Ŀ������С����)
                //����δ���˻�ֱ�ӷ����Ŀ�꣬�򲻼ٶ���������ˣ�����ʾ��Ҳ�Ǵ���ģ�
                MatrixXf A(2, 2), B(3, 2);
                B << 2, 0, 0, 3, 1, 1;
                A << 2, 0, 0, -2;
                A = (B * A).cwiseAbs(); // ���ڲ��ٶ�������������Ҫ������ʾ����
                cout << A << endl;
        }
        {
                //�����κλ������⣬��������ͨ���ڸ�ֵ֮ǰ��ʽ�������ʽ���������
                MatrixXf A(2, 2), B(3, 2);
                B << 2, 0, 0, 3, 1, 1;
                A << 2, 0, 0, -2;
                A = (B * A).eval().cwiseAbs();
                cout << A << endl;

                // Output is
                // 4 0
                // 0 6
                // 2 2
        }
}


Section10_StorageOrders

//����Ͷ�ά���������ֲ�ͬ�Ĵ洢˳�������Ⱥ������ȡ���ҳ˵������Щ�洢˳���Լ����ָ��Ӧʹ�õĴ洢˳�򡣾������Ŀ�γ�һ����ά���񡣵��ǣ�������洢�ڴ洢����ʱ��������ĳ�ַ�ʽ����������Ŀ����������Ҫ��������������һ�㣬���кͰ��С�����˵������**�������ȴ洢**�����ȴ洢������һ�У�Ȼ��洢�����ڶ��У��������ơ���һ���棬������������д洢�ģ���������˳��洢����������һ�п�ʼ��Ȼ���������ڶ��У��������ơ�

//����ͨ��OptionsΪMatrix��Arrayָ��ģ����������þ�����ά����Ĵ洢˳��
//����Matrix����ͣ�Matrix��ģ��������ģ�������
// ����������ǿ���Եģ�Scalar��RowsAtCompileTime��ColsAtCompileTime�������ǿ�ѡ�ģ�Options��MaxRowsAtCompileTime��MaxColsAtCompileTime�������Options��������ΪRowMajor��������������������˳��洢�������������ΪColMajor������������˳��洢�����δָ���洢˳����EigenĬ�Ͻ���Ŀ�洢��column-major�С���������typedef��Matrix3f��ArrayXXd�ȣ�Ҳ��Ĭ�ϰ��д洢��

//���Խ�ʹ��һ�ִ洢˳��ľ������������ʹ����һ�ִ洢˳��ľ�������飬��һ�����д洢�ľ���ʹ�ð��д洢�����ʼ����
//Eigen���Զ���Ԫ���������򡣸�һ����ԣ����д洢����Ͱ��д洢������Ը�����Ҫ�ڱ��ʽ�л��ʹ�á�

//��������������˳��洢ʱ�����б���������㷨����죬��Ϊ����λ�ø��á�ͬ����������Ҫ�о������б������졣������Ҫ����һ�����ҳ��������ض�Ӧ�ó������ķ�����
//Eigen�е�Ĭ��ֵ��column-major����Ȼ����Eigen��Ĵ���������Ͳ��Զ���ʹ������������ɵġ�����ζ�ţ���ʹ����ּ��͸����֧�������洢�������洢˳��Eigen��Ҳ����������洢�������ʹ�á�
void testColumnAndRowMajorStorage()
{
        // PlainObjectBase::data()  ���ص�һ��Ԫ�ص��ڴ�λ�ã���C++������������һ��

        Matrix<int, 3, 4, ColMajor> Acolmajor;
        Acolmajor << 8, 2, 2, 9,
            9, 1, 4, 4,
            3, 5, 4, 5;
        cout << "The matrix A:" << endl;
        cout << Acolmajor << endl
             << endl;
        cout << "In memory (column-major):" << endl;
        for (int i = 0; i < Acolmajor.size(); i++)
                cout << *(Acolmajor.data() + i) << "  ";
        cout << endl
             << endl;
        Matrix<int, 3, 4, RowMajor> Arowmajor = Acolmajor;
        cout << "In memory (row-major):" << endl;
        for (int i = 0; i < Arowmajor.size(); i++)
                cout << *(Arowmajor.data() + i) << "  ";
        cout << endl;

        // In memory (column-major):
        // 8  9  3  2  1  5  2  4  4  9  4  5

        // In memory (row-major):
        // 8  2  2  9  9  1  4  4  3  5  4  5
}



����

namespace Section11_AlignmentIssues
{
// �������
//Eigen::internal::matrix_array<T, Size, MatrixOptions, Align>::internal::matrix_array()
// [with T = double, int Size = 2, int MatrixOptions = 2, bool Align = true]:
// Assertion `(reinterpret_cast<size_t>(array) & (sizemask)) == 0 && "this assertion
// is explained here: http://eigen.tuxfamily.org/dox-devel/group__TopicUnalignedArrayAssert.html
//      READ THIS WEB PAGE !!! ****"' failed.

// �����ҵ����򴥷�λ�ã�
// ���磬
//$gdb ./my_program
//>run
//...
//>bt
//Ȼ���������4��ԭ��Ժ��������޸Ĵ���

// �� ����ԭ��

// ԭ��1:�ṹ���о���Eigen�����Ա
//��ע�⣬�˴�Eigen :: Vector2d������ʾ����
//��һ����ԣ����й̶���С�Ŀ�ʸ����Eigen���Ͷ�����ִ�����
//�̶���С�Ŀ�ʸ����Eigen��������������й̶��Ĵ�С���Ҵ�С��16�ֽڵı���
// Eigen::Vector2d
// Eigen::Vector4d
// Eigen::Vector4f
// Eigen::Matrix2d
// Eigen::Matrix2f
// Eigen::Matrix4d
// Eigen::Matrix4f
// Eigen::Affine3d
// Eigen::Affine3f
// Eigen::Quaterniond
// Eigen::Quaternionf

// ����, "�̶���С"Ӧ�����������ڱ���ʱ��Eigen����������������ǹ̶��ģ�����̶���С��
// ��ˣ�����Matrix3f���й̶���С����MatrixXfû�У��̶���С�Ķ����Ƕ�̬��С����
// �̶���С��Eigen�����ϵ����������ͨ��"��̬����"�����ᶯ̬���䡣���磬Matrix4f���������ֻ��һ��"float array[16]"��
// �̶���С�Ķ���ͨ����С������ζ������Ҫ���������ʱ���������ڴ�ʹ�ú��ٶȷ��棩���������ǡ�
// ���ڣ�ʸ������SSE��AltiVec�������Դ���128λ���ݰ������⣬��������ԭ����Щ���ݰ��������128λ���롣��ˣ���ʵ֤�����̶���С��Eigen���������������Ψһ�����ǣ�������ǵĴ�С��128λ��16���ֽڵı�����Ȼ��Eigen��Ϊ��Щ��������16�ֽڶ��룬���Ҵ˺���������Щ������ж��룬��˲���ִ������ʱ����Խ��ж��롣
// class Foo
// {
//   //...
//   Eigen::Vector2d v;
//   //...
// };
// //...
// Foo *foo = new Foo;

// Eigen��ҪEigen :: Vector2d�����飨2��˫���ȣ���128λ���롣����GCC������ͨ�����ԣ���aligned��16��������ɵġ�
// Eigen������Eigen :: Vector2d��" operator new"���������ʼ�շ���128λ�����ָ�롣
// ��ˣ�ͨ������£������ص����κ����飬Eigen��Ϊ���������...

// ...����һ���������������������Foo�࣬��������������̬�����µ�Fooʱ��������Fooû�ж���" operator new"����˷��ص�ָ��foo��һ����128λ����ġ�
// Ȼ�󣬳�Աv��alignment�����������Ŀ�ͷfoo�����fooָ��δ���룬��foo-> vҲ������룡
// �����������Foo�����һ�µ�"Operator new"

// ���������
//�������Ľṹ���й̶���С�Ŀ�ʸ����Eigen���͵ĳ�Ա�������������" operator new"���Ա�������16�ֽڶ����ָ�롣���˵��ǣ�EigenΪ���ṩ��һ����EIGEN_MAKE_ALIGNED_OPERATOR_NEW��Ϊ��ִ�д˲��������仰˵������һ���࣬������й̶���С�Ŀ�ʸ����Eigen������Ϊ��Ա��Ȼ��̬��������Ķ��󡣺ܼ򵥣���ֻ�轫EIGEN_MAKE_ALIGNED_OPERATOR_NEW������������public����
// class Foo
// {
//         Eigen::Vector2d v;
//         public : EIGEN_MAKE_ALIGNED_OPERATOR_NEW
// };
// Foo *foo = new Foo;
//�ú�ʹ" new Foo"ʼ�շ��ض����ָ�롣
//һ�� Eigen::Vector2d������double���ͣ�һ��doubleΪ8�ֽ�=64λ����һ��Eigen::Vector2dΪ128λ
//��ǡ����SSE���ݰ��Ĵ�С����ʹ�ÿ���ʹ��SSE�Ը�����ִ�и��ֲ���������SSEָ�����Eigenʹ�õ��ǿ���ָ���Ҫ128λ���롣�������ֶδ��󡣳������ԭ��Eigen�Լ�ͨ��ִ���������������Ҫ���Eigen :: Vector2d����128λ���룺


//ԭ��2��STL�������ֶ��ڴ����
///�������Stl����������std :: vector��std :: map�ȣ�
//��Eigen��������Eigen�������һ��ʹ�ã�
// std::vector<Eigen::Matrix2f> my_vector;
// struct my_class { ... Eigen::Matrix2f m; ... };
// std::map<int, my_class> my_map;
//��ע�⣬�˴�Eigen :: Matrix2f������ʾ������һ����ԣ��������й̶���С�Ŀ�ʸ����Eigen���ͺ;��д���Eigen������Ϊmember�Ľṹ��������ִ����⡣�κ���/���������ƹ�new�����ڴ���������Ҳ����ͨ��ִ���Զ����ڴ���䣬Ȼ�����placement new�������Ҳ�������ͬ�����⡣���磬ͨ���������������std::make_shared����std::allocate_shared���������ʹ�ö���ķ���������STL�������������������

//ԭ��3��ͨ��ֵ����Eigen����
//����������е�ĳЩ��������ͨ��ֵ����Eigen��������������
//void func(Eigen::Vector4d v);
//��ô����Ҫ�Ķ����µ�����ҳ�棺��Eigen����ֵ���ݸ���������ע�⣬�˴�Eigen :: Vector4d������ʾ������һ����ԣ����й̶���С�Ŀ�ʸ����Eigen���Ͷ�����ִ�����


// 3  ��statement��һ�����:
// �̶���С��ʸ����Eigen������������16�ֽڶ����λ�ô���������Ѱַ���ǵ�SIMDָ�������Eigenͨ����Ϊ�������Щ�������⣬�������ڹ̶���С�Ŀ�ʸ�������������ö������ԣ����������ǵ�" operator new"�����ǣ���ĳЩ��������£���Щ�������ûᱻ���ǣ������Ǵ˶��ԵĿ���ԭ��

}



Section1_LinearAlgebraAndDecompositions
{
//��ҳ˵��������������ϵͳ��������ַֽ⣬����LU��QR��SVD�������ֽ�...
//����������� Ax=b
void BasicLinearSolving()
{
        Matrix3f A;
        Vector3f b;
        A << 1, 2, 3, 4, 5, 6, 7, 8, 10;
        b << 3, 3, 4;
        cout << "Here is the matrix A:\n"
             << A << endl;
        cout << "Here is the vector b:\n"
             << b << endl;
        Vector3f x = A.colPivHouseholderQr().solve(b);
        cout << "The solution is:\n"
             << x << endl;

        //�ڴ�ʾ���У�colPivHouseholderQr��������������ColPivHouseholderQR�Ķ���
        //���ڴ˴��ľ�������ΪMatrix3f����˸��п������滻Ϊ��ColPivHouseholderQR <Matrix3f> dec��A��;
        //Vector3f x = dec.solve��b��;�����ColPivHouseholderQR�Ǿ���ѡ������Ԫ���ܵ�QR�ֽ⡣���Ǳ��̵̳�һ����������Է�������Ϊ�����������о��󣬶����ٶȷǳ��졣����һЩ�����ֽ�������Ը��ݾ����Ҫ���е�Ȩ��ѡ��
        {
                //������Щ�ֽⶼ�ṩ��һ��solve�����������÷���������ʾ��һ����
                //���磬������ľ����������ģ����ϱ�˵��LLT��LDLT�ֽ���һ���ܺõ�ѡ������һ��ʾ����Ҳ˵��ʹ��ͨ�þ��󣨶���ʸ������Ϊ���ֱ��ǿ��ܵġ�
                Matrix2f A, b;
                A << 2, -1, -1, 3;
                b << 1, 2, 3, 1;
                cout << "Here is the matrix A:\n"
                     << A << endl;
                cout << "Here is the right hand side b:\n"
                     << b << endl;
                Matrix2f x = A.ldlt().solve(b);
                cout << "The solution is:\n"
                     << x << endl;
        }
}

void CheckingIfASolutionReallyExists()
{
        //����������ķ���
        //ֻ����֪��Ҫ��������������Ϊ��Ч����Χ����ˣ�Eigen�������Լ����д˼��㣬������ʾ����ʾ��
        MatrixXd A = MatrixXd::Random(100, 100);
        MatrixXd b = MatrixXd::Random(100, 50);
        MatrixXd x = A.fullPivLu().solve(b);
        double relative_error = (A * x - b).norm() / b.norm(); // norm() is L2 norm
        cout << "The relative error is:\n"
             << relative_error << endl;
}

void ComputingEigenvaluesAndEigenvectors()
{
        //����Ҫ�ڴ˴����������ֽ⣬ ȷ���������Ƿ����԰���ģ�����ѧ�������һ������ά���ڻ��ռ䣬һ���԰�����(self-adjoint operator)�����Լ��İ������ӣ��ȼ۵�˵������԰����ӵľ����ǰ������ؾ��󡣰������ؾ�������Լ��Ĺ���ת�á���������ά���׶����ض�������һ��������һ�������Ա���԰�����Ϊһ��ʵֵ�ĶԽǾ��󡣾�������Щ�����о�������������������һ��ʹ��SelfAdjointEigenSolver��ʾ��������ʹ��EigenSolver��ComplexEigenSolver���ɵؽ���Ӧ����һ���������ֵ�����������ļ��㲻һ����������������������ʧ�ܵ�������١�����info��������Ϊ�˼�����ֿ����ԡ�
        Matrix2f A;
        A << 1, 2, 2, 3;
        SelfAdjointEigenSolver<Matrix2f> eigensolver(A);
        if (eigensolver.info() != Success)
                abort();
        cout << "The eigenvalues of A are:\n"
             << eigensolver.eigenvalues() << endl;
        cout << "Here's a matrix whose columns are eigenvectors of A \n"
             << "corresponding to these eigenvalues:\n"
             << eigensolver.eigenvectors() << endl;
}

void ComputingInverseAndDeterminant()
{
        //�����ͨ��������solve�����������棬������ʽͨ�����Ǽ������Ƿ����ĺ÷��������ǣ����ڷǳ�С�ľ������������ǲ���ȷ�ģ������������ʽ���ܷǳ����á�����ĳЩ�ֽ⣨����PartialPivLU��FullPivLU���ṩ��inverse������determinant��������������Ҳ����ֱ���ھ����ϵ���inverse������determinant�������������Ĺ̶���С��С�����Ϊ4x4����EigenӦ����ִ��LU�ֽ⣬��Ӧʹ�öԴ���С�������Ч�Ĺ�ʽ��
        Matrix3f A;
        A << 1, 2, 1,
            2, 1, 0,
            -1, 1, 2;
        cout << "Here is the matrix A:\n"
             << A << endl;
        cout << "The determinant of A is " << A.determinant() << endl;   //����ʽ
        cout << "The inverse of A is:\n"
             << A.inverse() << endl;
}

void LeastSquaresSolving()
{
        //��С����������׼ȷ������SVD�ֽ⡣Eigen�ṩ������ʵ�֡��Ƽ��Ķ�����BDCSVD�࣬�����Ժܺõؽ���ϴ�����⣬���Զ��˻ص�JacobiSVD���Խ����С�����⡣�����������࣬���ǵ�resolve�����������ڽ�����С������⡣
        MatrixXf A = MatrixXf::Random(3, 2);
        cout << "Here is the matrix A:\n"
             << A << endl;
        VectorXf b = VectorXf::Random(3);
        cout << "Here is the right hand side b:\n"
             << b << endl;
        cout << "The least-squares solution is:\n"
             << A.bdcSvd(ComputeThinU | ComputeThinV).solve(b) << endl;

        //���ܸ��쵫�ɿ��Խϵ͵���һ�ַ�����ʹ�þ����Cholesky�ֽ��QR�ֽ⡣���ǹ�����С���˷�����ҳ���и�����ϸ��Ϣ��
}

void SeparatingTheComputationFromTheConstruction()
{
        // ������ʾ���У��ڹ���ֽ�����ͬʱ�����˷ֽ⡣���ǣ���ĳЩ����£�������ϣ�����������·ֿ���
        //���磬����ڹ���ʱ��֪��Ҫ�ֽ�ľ�������ܻ���Ҫ�����Ƿֿ������������������еķֽ����
        // ʹ֮��Ϊ���ܵ�ԭ���ǣ�
        // ���зֽⶼ��Ĭ�ϵĹ��캯����
        // ���зֽⶼ����ִ�м����compute��matrix�����������ҿ������Ѽ���ķֽ����ٴε��ø÷������Խ������³�ʼ����
        Matrix2f A, b;
        LLT<Matrix2f> llt;
        A << 2, -1, -1, 3;
        b << 1, 2, 3, 1;
        cout << "Here is the matrix A:\n"
             << A << endl;
        cout << "Here is the right hand side b:\n"
             << b << endl;
        cout << "Computing LLT decomposition..." << endl;
        llt.compute(A);
        cout << "The solution is:\n"
             << llt.solve(b) << endl;
        //��������Ը��߷ֽ⹹�캯��Ԥ�ȷ���洢�ռ��Էֽ������С�ľ����Ա������ֽ�������ʱ����ִ�ж�̬�ڴ���䣨��Ȼ�������ʹ�õ��ǹ̶���С�ľ����򲻴��ڶ�̬�ڴ������ȫ��������ֻ�轫��С���ݸ��ֽ⹹�캯��������ɣ�������ʾ����ʾ��
        {
                HouseholderQR<MatrixXf> qr(50, 50);
                MatrixXf A = MatrixXf ::Random(50, 50);
                qr.compute(A); //û�ж�̬�ڴ����
        }
}
void RankRevealingDecompositions()
{
        //ĳЩ�ֽ��ǽ�ʾ�����ȵġ�
        //��Щͨ��Ҳ���ڷ����Ⱦ����ڷ�������±�ʾ������󣩵�����±�����ѵķֽ⡣
        //�Ƚ�ʾ�ֽ������ṩ��rank()���������ǻ������ṩ����ķ���������isInvertible()��
        //���һ��ṩһЩ�������������ĺˣ���ռ䣩�����пռ䣩������FullPivLU������
        Matrix3f A;
        A << 1, 2, 5,
            2, 1, 4,
            3, 0, 3;
        cout << "Here is the matrix A:\n"
             << A << endl;
        FullPivLU<Matrix3f> lu_decomp(A);
        cout << "The rank of A is " << lu_decomp.rank() << endl;
        cout << "Here is a matrix whose columns form a basis of the null-space of A:\n"
             << lu_decomp.kernel() << endl;
        cout << "Here is a matrix whose columns form a basis of the column-space of A:\n"
             << lu_decomp.image(A) << endl; // yes, have to pass the original A

        // Output is:
        // Here is the matrix A:
        // 1 2 5
        // 2 1 4
        // 3 0 3
        // The rank of A is 2
        // Here is a matrix whose columns form a basis of the null-space of A:
        //  0.5
        //    1
        // -0.5
        // Here is a matrix whose columns form a basis of the column-space of A:
        // 5 1
        // 4 2
        // 3 3

        //��Ȼ���κ��ȼ��㶼ȡ���ڶ�������ֵ��ѡ����Ϊʵ����û�и������ǡ�����Ȳ���ġ�Eigenѡ��һ�����ǵ�Ĭ����ֵ������ֵȡ���ڷֽ⣬��ͨ���ǶԽ��ߴ�С���Ի����š���Ȼ�������ǿ���ѡ������Ĭ��ֵ����ֻ����֪������Ӧ�ó������ȷ��ֵ�Ƕ��١�������ͨ���ڵ���rank��������Ҫʹ�ô���ֵ���κ���������֮ǰ�ڷֽ�����ϵ���setThreshold�������������á��ֽⱾ����compute��������������ֵ�޹ء�������ֵ���������¼���ֽ�.
        {
                Matrix2d A;
                A << 2, 1,
                    2, 0.9999999999;
                FullPivLU<Matrix2d> lu(A);
                cout << "By default, the rank of A is found to be " << lu.rank() << endl;
                lu.setThreshold(1e-5);
                cout << "With threshold 1e-5, the rank of A is found to be " << lu.rank() << endl;

                // Output is:
                // By default, the rank of A is found to be 2
                // With threshold 1e-5, the rank of A is found to be 1
        }
}

Section2_CatalogueOfDenseDecompositions
{
// ��ҳ����ʾ��Eigen�ṩ�ĳ��ܾ���ֽ��Ŀ¼��������ɾ���� �Լ��ң�

// �ʼǣ�
// 1��LDLT�㷨�����ֱ��塣Eigen��һ�����ɴ��Խ�D������������ܴ������ľ�������Lapack��һ�����ɿ�Խ�D����ͬ��
// 2������ֵ��SVD��Schur�ֽ������ڵ����㷨�����ǵ������ٶ�ȡ��������ֵ�ķ���̶ȡ�
// 3�����ǵ�JacobiSVD��˫��ģ���Ϊƽ�������ṩ������֤����Ѿ��ȡ����ڷ�ƽ���������Ǳ�������ʹ��QRԤ��������Ĭ��ѡ��ColPivHouseholderQR�Ѿ��ǳ��ɿ��������������֤����һ�㣬�����FullPivHouseholderQR��
// ���
// �԰飺����ʵ�����԰��ǶԳƵ�ͬ��ʡ����ڸ��ӵľ����԰�Ϊͬ��ʰ������ء���һ��أ�A���ҽ���������������ʱA*����������԰����$ A ^ * $������Ҳ��Ϊ����ת�á�
// Blocking
// ��ζ�Ÿ��㷨���԰��鹤�����Ӷ���֤�˴��;������ܵ��������š�
// ��ʽ���̣߳�MT��
// ��ζ�Ÿ��㷨����ͨ��OpenMP���ö�˴�������"��ʽ"��ָ�㷨�����ǲ��еģ����������ڲ��о������˻��Ĺ���
// ��ʽ���̣߳�MT��
// ��ζ�Ÿ��㷨����ʽ���л�����ͨ��OpenMP���ö�˴�������
// Ԫչ����
// ��ζ�Ŷ��ں�С�Ĺ̶���С���󣬸��㷨���Զ���ʽչ����
} 

